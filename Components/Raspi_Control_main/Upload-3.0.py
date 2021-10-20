#!/usr/bin/python3

# This deals with all uploading work, incl. uploading images and sensor data to Adafruit and Googl drive.

from Adafruit_IO import Client
from PIL import Image
import base64
from datetime import datetime, timedelta
import time 
import os
import pandas as pd
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

def check_folder(date):
    # Input a date and check if folder of that date exists on google drive
    folders = drive.ListFile({'q': "title='" + date + "' and mimeType='application/vnd.google-apps.folder' and trashed=false"}).GetList()
    
    if len(folders) == 0: # No folder
        return(0)
    else:
        return(1)

if __name__ == '__main__':

    #--------------------------------------------------- Configure Adafruit-IO---------------------------------
    print('Connecting to Adafruit-IO...')
    aio = Client(username = 'Deebug',key = 'xxx') # Put username and AIO key here
    print('Adafruit-IO Connected!')

    camera_feed = aio.feeds('pi-camera')
    image = '/home/pi/Documents/Chamber/snapshot.jpg' 

    temp_bme_feed = aio.feeds('temp-bme')
    temp_ntc_feed = aio.feeds('temp-ntc')
    temp_lm75_feed = aio.feeds('temp-lm75') 
    pressure_feed = aio.feeds('pressure') 
    hum_feed = aio.feeds('humidity') # TODO Can add more sensor feeds

    count = 0 # This is to count how many images have been taken and uploaded and also report the number of loops.

    now = datetime.now()
    current_time = now.strftime('%Y-%m-%d %H:%M:%S')
    print(str(current_time) + ': live stream and data logging starts.')

    #--------------------------------------------------- Loop---------------------------------

    while True:

        now = datetime.now()
        current_time = now.strftime('%Y-%m-%d %H:%M:%S')
        current_time_v2 = now.strftime('%Y-%m-%d_%H.%M.%S')
        current_day = now.strftime('%y%m%d')
        yesterday = datetime.today() - timedelta(days = 1)
        yester_day = yesterday.strftime('%y%m%d')
        past = datetime.today() - timedelta(days = 3)
        past_day = past.strftime('%y%m%d')

        #-----------------------------------Upload to Adafruit-------------------------------------------------------------
        # Image
        with open(image, "rb") as imageFile: # read snapshot and encode it to base64 format
            base_str = base64.b64encode(imageFile.read())
            base_str = base_str.decode('utf-8')

            aio.send_data(camera_feed.key, base_str) # Send data to Adafruit-IO. First argument is the name of your feed.
            
            count = count + 1
            if count % 10 == 0:
                print(str(current_time) + ': ' + str(count) + ' images uploaded to Adafruit-io...')
            elif count == 1:
                print(str(current_time) + ': ' + str(count) + ' image uploaded to Adafruit-io...')

        # sensor data 
        if not os.path.exists(current_day): # This is to make sure that on a new day, Upload-x.x.py will only upload sensor data 'after' Local-x.x.py has created that new day's folder and csv file. If not, Upload-x.x.py will in theory wait for one loop.
            continue

        filename = './'+ current_day + '/log_' + current_day + '.csv'
        df = pd.read_csv(filename)
        parameter = df.iloc[-1,1:] # a list of parameters: Temp (BME680), pressure, humidity, Temp (LM75), Temp (NTC), Pressure, Humidity

        aio.send_data(temp_lm75_feed.key, parameter[0])
        aio.send_data(temp_bme_feed.key, parameter[1])
        aio.send_data(temp_ntc_feed.key, parameter[2])
        aio.send_data(pressure_feed.key, parameter[3])
        aio.send_data(hum_feed.key, parameter[4])

        #---------------------------------Upload to Google Drive-------------------------
        #Upload csv
        if not check_folder(current_day): # On a new day, create a folder on Google drive named with the date, save .csv of previous date, and save images on that date.

            folder_metadata = {'title' : current_day, 'mimeType' : 'application/vnd.google-apps.folder'}
            folder = drive.CreateFile(folder_metadata)
            folder.Upload()

            #-------------------------------Upload yesterday's .csv log file to google drive-----------------------
            if os.path.exists(yester_day):
                csv_file = drive.CreateFile({'title' : 'log_' + yester_day + '.csv', 'mimeType':'image/jpeg', 'parents': [{'id': folderid(yester_day)}]})
                csv_file.SetContentFile(yester_day + '/log_' + yester_day + '.csv')
                csv_file.Upload()

            #-------------------------------Auto delete data from 3 days ago on Raspberry pi to save local memory-----------------------
            if check_folder(past_day): # check if old data has been saved on google drive
                shutil.rmtree(past_day)                                                 
        
        #Upload images
        img_list = [x for x in os.listdir(current_day) if x.endswith(".jpg")]
        if img_list:
            for i in img_list:

                    img_file = drive.CreateFile({'title' : i, 'mimeType':'image/jpeg', 'parents': [{'id': folderid(current_day)}]})
                    img_file.SetContentFile(current_day + '/' + i)
                    img_file.Upload()

                    os.remove(current_day + '/' + i)          

        time.sleep(30) # repeat every roughly 30 seconds (actually a bit longer than 60s as the image cature takes another 1-2 s)