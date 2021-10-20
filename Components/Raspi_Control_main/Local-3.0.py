#!/usr/bin/python3

# This deals with all local work, incl. communicating with Arduino board, take images and sensor data and save to local folders.

import serial
from PIL import Image
import base64
from datetime import datetime, timedelta
import time 
import os

dir_base = '/home/pi/Documents/Chamber/'

water_interval = 60 # number of hours between each watering event

def irrigation(Water_Interval = water_interval):
    now = datetime.now()

    last_water_str = open('WaterLog','r').read().rstrip('\n')
    last_water = datetime.strptime(last_water_str, '%M.%H.%d.%m.%y') # read the time of last watering event from WaterLog file. Time is stored in this file as a string in the format 'minute.hour.day.month.year'
    delta = now - last_water
    if (delta.days*24 + delta.seconds/3600) > Water_Interval:
        ser.write(b'water\n') # send a 'water' signal to Arduino board
        os.system('echo ' + now.strftime('%M.%H.%d.%m.%y') + ' > WaterLog') 

if __name__ == '__main__':

    #--------------------------------------------------- Configure serial communication---------------------------------
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
    count = 0 

    now = datetime.now()
    current_time = now.strftime('%Y-%m-%d %H:%M:%S')
    print(str(current_time) + ': Communication between Arduino established!')
    #--------------------------------------------------- Loop---------------------------------

    while True:

        if ser.in_waiting == 0:
            continue

        now = datetime.now()
        current_time = now.strftime('%Y-%m-%d %H:%M:%S')
        current_time_v2 = now.strftime('%Y-%m-%d_%H.%M.%S')
        current_day = now.strftime('%y%m%d')
        yesterday = datetime.today() - timedelta(days = 1)
        yester_day = yesterday.strftime('%y%m%d')
        past = datetime.today() - timedelta(days = 3)
        past_day = past.strftime('%y%m%d')

        #-----------------------------------image capture -------------------------------------------------------------
        os.system('fswebcam -d v4l2:/dev/video0 -q --no-banner --jpeg 80 --set brightness=40% --save /home/pi/Documents/Chamber/snapshot.jpg') # uses fswebcam to take a picture. -q: quite mode. -r: image resolution. --jpeg 60: quality of the images (can be 0-95).
        count = count + 1
        if count % 10 == 0:
            print(str(current_time) + ': ' + str(count) + ' images taken')
        elif count == 1:
            print(str(current_time) + ': ' + str(count) + ' image taken')

        #-----------------------------------sensor data upload-------------------------------------------------------------

        if ser.in_waiting > 0:
            
            line = ser.readline().decode('utf-8').rstrip()
            parameter = line.split(',') # a list of parameters: Temp (BME680), pressure, humidity, Temp (LM75), Temp (NTC), Pressure, Humidity

            header = 'Time,Temp_LM75/oC,Temp_BME680/oC,Temp_NTC/oC,Pressure/kPa,Humidity/%'

        #---------------------------------Save csv files and images together into folders-------------------------

        if not os.path.exists(current_day): # On a new day, create a folder named with the date and save upcoming .csv and images on that date to that folder.
            os.makedirs(current_day)
            os.system('echo ' + header + ' >> ' + current_day + '/log_$(date +%y%m%d).csv') # create .csv log file for that day and add the header

        datalog = str(current_time) + ',' + str(line)
        os.system('echo ' + datalog + ' >> ' + current_day + '/log_$(date +%y%m%d).csv')
    
        if count % 60 == 0: # Take a high-resolution image 
            os.system('raspistill -o ' + current_day + '/' + current_time_v2 + '.jpg')

        #-------------------------------Auto-irrigation every two days-----------------------
        if count % 120 == 0: # Check if it is time to water every 1 hour.
            irrigation()

        time.sleep(30) # repeat every roughly 30 seconds (actually a bit longer than 60s as the image cature takes another 1-2 s)
        ser.reset_input_buffer()
