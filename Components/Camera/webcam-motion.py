#!/usr/bin/python3

from Adafruit_IO import Client
from PIL import Image
import base64
from datetime import datetime

aio = Client(username = 'Deebug',key = 'aio_vtRS59BNUhOGeqzjA4ma5AGaLrlr') # username and AIO key here
image = '/home/pi/Camera/lastsnap.jpg' # This is where images are saved, set in config file.

with open(image, "rb") as imageFile:
    base_str = base64.b64encode(imageFile.read())
    base_str = base_str.decode('utf-8')

camera_feed = aio.feeds('pi-camera')
aio.send_data(camera_feed.key, base_str) # First argument is the name of your feed.

now = datetime.now()
current_time = now.strftime("%H:%M:%S")

# f = open("/home/pi/Camera/log.txt", "a+")
# f.write(current_time + ": Image uploaded. Base64 = " + str(base_str) + '\n')
# f.close()
