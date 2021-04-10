#!/usr/bin/python3

# This will be the main Python script to upload images and sensor data to Adafruit-IO

import serial
from Adafruit_IO import Client
from PIL import Image
import base64
from datetime import datetime, timedelta
import time 
import os
import shutil
from pydrive.drive import GoogleDrive
from pydrive.auth import GoogleAuth

gauth = GoogleAuth()
gauth.CommandLineAuth()
drive = GoogleDrive(gauth) # Create GoogleDrive instance with authenticated GoogleAuth instance.

dir_base = '/home/pi/Documents/Chamber/'

def folderid(date):
    # Input a date and return the folder ID of that date
    folders = drive.ListFile({'q': "title='" + date + "' and mimeType='application/vnd.google-apps.folder' and trashed=false"}).GetList()
    
    if len(folders) == 1: # make sure folder is unique
        return(folders[0]['id'])
    elif len(folders) == 0:
        print('Error: Cannot Find Folder on Google Drive: ' + date)
    elif len(folders) > 1: 
        print('Error: Duplicate Folder on Google Drive: ' + date)

if __name__ == '__main__':

    #--------------------------------------------------- Configure serial communication---------------------------------
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
    
    #--------------------------------------------------- Configure Adafruit-IO---------------------------------
    aio = Client(username = 'Deebug',key = 'xxx') # Put username and AIO key here

    camera_feed = aio.feeds('pi-camera')
    image = '/home/pi/Documents/Chamber/snapshot.jpg' 

    temp_bme_feed = aio.feeds('temp-bme')
    temp_ntc_feed = aio.feeds('temp-ntc')
    temp_lm75_feed = aio.feeds('temp-lm75') 
    pressure_feed = aio.feeds('pressure') 
    hum_feed = aio.feeds('humidity') # TODO Can add more sensor feeds

    count = 0 # This is to count how many images have been taken and uploaded and also report the number of loops.

    now = datetime.now()
    current_time = now.strftime('%H.%M.%S')
    print(str(current_time) + ': live stream and data logging starts.')

    #--------------------------------------------------- Loop---------------------------------

    while True:

        now = datetime.now()
        current_time = now.strftime('%H.%M.%S')
        current_day = now.strftime('%y%m%d')
        yesterday = datetime.today() - timedelta(days = 1)
        yester_day = yesterday.strftime('%y%m%d')
        past = datetime.today() - timedelta(days = 3)
        past_day = past.strftime('%y%m%d')

        #-----------------------------------image capture and upload-------------------------------------------------------------
        os.system('fswebcam -q --no-banner --jpeg 80 --save /home/pi/Documents/Chamber/snapshot.jpg') # uses fswebcam to take a picture. -q: quite mode. -r: image resolution. --jpeg 60: quality of the images (can be 0-95).
            
        with open(image, "rb") as imageFile: # read snapshot and encode it to base64 format
            base_str = base64.b64encode(imageFile.read())
            base_str = base_str.decode('utf-8')

            aio.send_data(camera_feed.key, base_str) # Send data to Adafruit-IO. First argument is the name of your feed.
            
            count = count + 1
            if count % 10 == 0:
                print(str(current_time) + ': ' + str(count) + ' images uploaded to Adafruit-io...')
            elif count == 1:
                print(str(current_time) + ': ' + str(count) + ' image uploaded to Adafruit-io...')

        #-----------------------------------sensor data upload-------------------------------------------------------------
        if ser.in_waiting > 0:
            
            line = ser.readline().decode('utf-8').rstrip()

            parameter = line.split(',') # a list of parameters: Temp (BME680), pressure, humidity, Temp (LM75), Temp (NTC)
            # a list of parameters: Temp (LM75), Temp (BME680), Temp (NTC), Pressure, Humidity

            aio.send_data(temp_lm75_feed.key, parameter[0])
            aio.send_data(temp_bme_feed.key, parameter[1])
            aio.send_data(temp_ntc_feed.key, parameter[2])
            aio.send_data(pressure_feed.key, parameter[3])
            aio.send_data(hum_feed.key, parameter[4])

            header = 'Time\(H.M.S\),Temp_LM75/oC,Temp_BME680/oC,Temp_NTC/oC,Pressure/kPa,Humidity/%'

        #---------------------------------Save csv files and images together into folders-------------------------

            if not os.path.exists(current_day): # On a new day, create a folder named with the date and save upcoming .csv and images on that date to that folder.
                os.makedirs(current_day)
                os.system('echo ' + header + ' >> ' + current_day + '/log_$(date +%y%m%d).csv') # create .csv log file for that day and add the header

                #---------------------------------Create a folder on google drive-----------------------
                folder_metadata = {'title' : current_day, 'mimeType' : 'application/vnd.google-apps.folder'}
                folder = drive.CreateFile(folder_metadata)
                folder.Upload()

                #-------------------------------Upload yesterday's .csv log file to google drive-----------------------
                csv_file = drive.CreateFile({'title' : 'log_' + yester_day + '.csv', 'mimeType':'image/jpeg', 'parents': [{'id': folderid(yester_day)}]})
                csv_file.SetContentFile(yester_day + '/log_' + yester_day + '.csv')
                csv_file.Upload()

                #-------------------------------Auto delete data from 3 days ago on Raspberry pi to save local memory-----------------------
                if os.path.exists(past_day):
                    shutil.rmtree(past_day)

            datalog = str(current_time) + ',' + str(line)
            os.system('echo ' + datalog + ' >> ' + current_day + '/log_$(date +%y%m%d).csv')
        
            if count % 60 == 0: # Upload an high-resolution image to google drive every half an hour.
                os.system('raspistill -o ' + current_day + '/' + current_time + '.jpg')

                img_file = drive.CreateFile({'title' : current_time + '.jpg', 'mimeType':'image/jpeg', 'parents': [{'id': folderid(current_day)}]})
                img_file.SetContentFile(current_day + '/' + current_time + '.jpg')
                img_file.Upload()



        time.sleep(30) # repeat every roughly 30 seconds (actually a bit longer than 60s as the image cature takes another 1-2 s)