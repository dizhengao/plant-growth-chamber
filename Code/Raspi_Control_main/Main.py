#!/usr/bin/python3

# This will be the main Python script to upload images and sensor data to Adafruit-IO

import serial
from Adafruit_IO import Client
from PIL import Image
import base64
from datetime import datetime
import time 
import os 

dir_base = '/home/pi/Documents/Chamber/'

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
    current_time = now.strftime('%H:%M:%S')
    print(str(current_time) + ': live stream and data logging starts.')

    #--------------------------------------------------- Loop---------------------------------

    while True:

        #-----------------------------------image capture and upload-------------------------------------------------------------
        os.system('fswebcam -q --no-banner --jpeg 80 --save /home/pi/Documents/Chamber/snapshot.jpg') # uses fswebcam to take a picture. -q: quite mode. -r: image resolution. --jpeg 60: quality of the images (can be 0-95).
            
        with open(image, "rb") as imageFile: # read snapshot and encode it to base64 format
            base_str = base64.b64encode(imageFile.read())
            base_str = base_str.decode('utf-8')

            aio.send_data(camera_feed.key, base_str) # Send data to Adafruit-IO. First argument is the name of your feed.

            now = datetime.now()
            current_time = now.strftime('%H:%M:%S')
            current_day = now.strftime('%y%m%d')
            
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

            header = 'Time,Temp_LM75/oC,Temp_BME680/oC,Temp_NTC/oC,Pressure/kPa,Humidity/%'

            fname = 'log_' + current_day + '.csv'
            if not os.path.isfile(fname): # in order to save each day's data into individual .csv files, we first check if a file coresponding to that date exists, if not we create the file and add header as the first line.
                os.system('echo ' + header + ' >> log_$(date +%y%m%d).csv')

            datalog = str(current_time) + ',' + str(line)
            os.system('echo ' + datalog + ' >> log_$(date +%y%m%d).csv')

        time.sleep(30) # repeat every roughly 60 seconds (actually a bit longer than 60s as the image cature takes another 1-2 s)
