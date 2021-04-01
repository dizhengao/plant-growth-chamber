#!/usr/bin/python3

from Adafruit_IO import Client
from PIL import Image
import base64
from datetime import datetime
import time 
import os 

aio = Client(username = 'Deebug',key = 'aio_vtRS59BNUhOGeqzjA4ma5AGaLrlr') # Put username and AIO key here
camera_feed = aio.feeds('pi-camera')
image = '/home/pi/Camera/snapshot.jpg' 
#f = open('/home/pi/Camera/log.txt', 'a+') # This is to write log files. Can disable this after tests as the log files may accumulate to take up a large space.

count = 0 # This is to count how many images have been taken and uploaded

now = datetime.now()
current_time = now.strftime('%H:%M:%S')
print(str(current_time) + ': live stream starts.')

while True:
    
    os.system('fswebcam -q -r 1280x720 --no-banner --jpeg 60 --save /home/pi/Camera/snapshot.jpg') # uses fswebcam to take a picture. -q: quite mode. -r: image resolution. --jpeg 60: quality of the images (can be 0-95).
    
    with open(image, "rb") as imageFile: # read snapshot and encode it to base64 format
        base_str = base64.b64encode(imageFile.read())
        base_str = base_str.decode('utf-8')

        aio.send_data(camera_feed.key, base_str) # Send data to Adafruit-IO. First argument is the name of your feed.

    now = datetime.now()
    current_time = now.strftime('%H:%M:%S')

    #f.write(current_time + ': Image uploaded. Base64 = ' + str(base_str) + '\n') # Writing log file for debugging purposes. Can change the content to test different parameters.
    
    count = count + 1
    if count % 10 == 0:
        print(str(current_time) + ': ' + str(count) + ' images uploaded to Adafruit-io...')
    elif count == 1:
        print(str(current_time) + ': ' + str(count) + ' image uploaded to Adafruit-io...')
    
    time.sleep(2) # repeat every roughly 2 seconds (actually a bit longer than 2s as the image cature takes another 1-2 s)

#f.close() # close log file. Disabled here.