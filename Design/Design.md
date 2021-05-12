# Design

This file summaries general design ideas and resources to build the project.

- [Design](#design)
  - [1. Ideas](#1-ideas)
  - [2. Questions](#2-questions)
  - [3. Reference](#3-reference)
    - [3.1. General](#31-general)
    - [3.2. Suppliers](#32-suppliers)
    - [3.3. Some Hackster projects](#33-some-hackster-projects)
    - [3.4. Hardware](#34-hardware)
      - [3.4.1. Relay](#341-relay)
      - [3.4.2. WiFi](#342-wifi)
      - [3.4.3. 4D Systems programmable touchscreen](#343-4d-systems-programmable-touchscreen)
    - [3.5. Software-Arduino IDE](#35-software-arduino-ide)
    - [3.6. Software-3D printing](#36-software-3d-printing)
    - [3.7. Software-XOD](#37-software-xod)
      - [3.7.1. XOD libraries for Open-Smart Rich UNO R3](#371-xod-libraries-for-open-smart-rich-uno-r3)
      - [3.7.2. Basic XOD elements](#372-basic-xod-elements)
    - [3.8. Other references](#38-other-references)
    - [3.9. Arduino-Rpi communication](#39-arduino-rpi-communication)
    - [3.10. Raspberry pi](#310-raspberry-pi)
  - [4. Knowledge](#4-knowledge)
    - [4.1. Electrical Sensors](#41-electrical-sensors)
    - [4.2. WiFi modules](#42-wifi-modules)
    - [4.3. Programming on Hardware](#43-programming-on-hardware)
    - [4.4. DIY](#44-diy)
  - [5. Papers](#5-papers)

## 1. Ideas

quick thoughts can be added here

[20210420-JMH] 1. To test watering system, fill plates with soil and see the change of soil color from camera. 2. Firmly press the soil by printing a 'presser' with the same dimensions as plates. 3. Whether use compost only or with vermiculite.

[20200303-ZD] Thermo cameras and fluorescence cameras. Also check out devices on [Photon](https://handheld.psi.cz/).

[20201203-ZD] To have another raspberry Pi with screen showing real time images and data logs, which can be put in home/lab bench so that you won't even have to have a computer to do the monitoring. It would be great if we have this along side with our prototype at the showcase event.

[20201125-Che] Lamp: Control RGB light separately; create different light intensity and RGB components for different experimental purposes.

[20201123-JMH] 1. Use robotic arm or something else to spray water from the top. This will be especially useful to water individual wells that are dried as a complement of watering from the bottom. 2. May include lime as CO2 scrubber to customize CO2 concentration for experiment purposes.

[20201115-ZD] Expand the prototype to larger scale: Use a robot with a camera to move around and take pictures of plants every xx minutes/hours; or install tracks for camera on the top of the chamber to take images every xx minute/hour.

## 2. Questions

*Mar 21*

1. [x] How to connect Arduino to Rpi, and use Rpi to upload data to a cloud?

*Feb 21 - sadly we no longer use XOD*

1. [x] How to search XOD nodes? 
2. [x] How to create our own nodes? And how hard/easy is this?
3. [x] Devices using I2C protocol- How to find out their address? Does each of device come with different address or we can customize the address?
4. [x] What is DONE used for on XOD?

## 3. Reference

### 3.1. General

[Letusgrow](https://www.lettusgrow.com)

### 3.2. Suppliers

- [RS](https://uk.rs-online.com/web/)
- https://thepihut.com/
- https://shop.sb-components.co.uk/collections/raspberry-pi
- https://shop.pimoroni.com/
- https://www.okdo.com/
- https://uk.farnell.com/?pf_custSiteRedirect=true
- https://www.thorlabs.com/

### 3.3. Some Hackster projects

- :star:[FytoScope Chamber FS 130](http://growth-chambers.com/products/small-fytoscopes/fytoscope-chamber-130/#details) from Photon
- [Biomaker Tutorial](https://www.hackster.io/159756/biomaker-tutorial-1-getting-started-4fc966)
- :star:[Lunaflow](https://www.hackster.io/lunaflow/lunaflow-bioluminescent-plankton-for-3d-flow-visualisation-d60cbe): incubator design, **temperature control**, real-time monitor camera, codes.
- [Variable-Time Camera for Monitoring Plant Pollination Events](https://www.hackster.io/team-ppi/variable-time-camera-for-monitoring-plant-pollination-events-ad21e7) A **video and time-lapse monitor** to record pollinators interacting with plants. This project included an environmental sensor to measure temperature, humidity and barometric pressure and wrote this data into the image file names for later analysis.
- [Biofab Incubator](https://www.hackster.io/170194/biofab-incubator-6f5b0e) A low cost programmable incubator for growing mycelium textile. This project uses sensors to measure temperature and humidity and feeds this information back into the system to maintain constant environmental conditions.- [eCO-SENSE](https://www.hackster.io/glen-chua/eco-sense-soil-sensors-powered-by-plant-photosynthesis-be80a2) A sensor to monitor soil conditions powered by plant growth. This project uses a temperature sensor, moisture sensor and gas sensor to take measurements of soil 68 conditions and adds a bluetooth module to send the data wirelessly to a phone or computer.
- [Low Cost Oxygen Sensor for Bioreactors](https://www.hackster.io/biomaker/low-cost-oxygen-sensor-for-bioreactors-c7e066) This project developed a custom low-cost oxygen sensor to measure oxygen levels in cultures of E. coli, and logged the data via an Arduino microcontroller. 
- [A Behavioural Chamber to Evaluate Rodent Forelimb Grasping](https://www.hackster.io/alejandrocarn/a-behavioural-chamber-to-evaluate-rodent-forelimb-grasping-bedb1a) This project uses a light emitter and light sensor to monitor when a rodent moves past a certain threshold, and triggers release of a sugar pellet when it does. 

Refer to some plant growth products and facility that have been using in real plant research (e.g. in PGF) and [gardin](https://gard.in/) (This is very expensive so probably we won't use them in our project.)

### 3.4. Hardware

#### 3.4.1. Relay

- [Connecting a 12v 8 Channel Relay to an External Power Supply and RaspberryPi](https://medium.com/@jinky32/connecting-a-12v-8-channel-relay-to-an-external-power-supply-and-raspberrypi-6fec119c112c)  
- [Control High Voltage Devices with Arduino](https://howtomechatronics.com/tutorials/arduino/control-high-voltage-devices-arduino-relay-tutorial/)

#### 3.4.2. WiFi

Arduino there are some modules based on the [ESP8266 microchip](https://en.wikipedia.org/wiki/ESP8266) such as Adafruit Feather HUZZAH (I have this!, read manual [here](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266)) or [SparkFun ESP8266 Thing Dev Board](learn.sparkfun.com/tutorials/esp8266-thing-development-board-hookup-guide).

#### 3.4.3. 4D Systems programmable touchscreen

[spec sheet](https://static1.squarespace.com/static/584d41b3f5e2310b396cd953/t/5ba376490e2e7299a6f96506/1537439314392/gen4-uLCD-32D_datasheet_R_1_5.pdf), [Introduction](https://static1.squarespace.com/static/584d41b3f5e2310b396cd953/t/5ba374cac2241b80e970e46f/1537438935415/Visi-Genie_userguide_R_2_0.pdf)

### 3.5. Software-Arduino IDE

Add resources here.

### 3.6. Software-3D printing

Add resources here.

### 3.7. Software-XOD

#### 3.7.1. XOD libraries for Open-Smart Rich UNO R3

- Real time clock module: datetime (https://xod.io/libs/xod/datetime/) and ds-rtc (https://xod.io/libs/xod- dev/ds-rtc/) libraries.
- Onboard LM75 temperature sensor: lm75a-temp-sensor node can be found in the gst/lm75atempsensor XOD library.
- Onboard 4-digit display: tm1637-dev node from the cesars/tm1637 or cesars/tm1637-v2 library. This library also contains other nodes for onboard display, such as tm1637-decex, tm1637-autorange, tm1637-digits (for string)
- Various onboard modules: cesars/rich-uno-r3, cesars/utils (contains nodes required by the her other libraries)
- sd-log node: from xod/commonhardware library, for saving data into SD card.
- OLED screen: wayland/ssd1306-oled-i2c library. Nodes: ssd1306-oled-i2c-device
- gweimer/utils

#### 3.7.2. Basic XOD elements

- Format number: *format-number* node
- *join* node

### 3.8. Other references

- [Robotic arm](https://shop.pimoroni.com/products/mearm-robot-raspberry-pi-kit?variant=21775370223699&currency=GBP&utm_source=google&utm_medium=cpc&utm_campaign=google+shopping?utm_source=google&utm_medium=surfaces&utm_campaign=shopping&gclid=Cj0KCQiA48j9BRC-ARIsAMQu3WTvhcmb-bZv5fxLHJMAYPL-1Bl-ShvdAIO8ML_nc9I4GpWhqUfcmDkaAn6uEALw_wcB), [Makeblock robot](https://www.makeblock.com/cn/mbot/)
- https://www.nature.com/articles/d41586-019-01590-z
- [Open-source lab](https://www.appropedia.org/Open-source_Lab)
- [BENEFICIAL BIO](https://beneficial.bio/)
- [Photon-plant phenotyping systems](http://plantphenotyping.com/)

### 3.9. Arduino-Rpi communication

An introduction [article](https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/).

Python packages: [pySerial API](https://pyserial.readthedocs.io/en/latest/pyserial_api.html)

On Arduino side: [UART](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

### 3.10. Raspberry pi

- [Pi Camera](https://projects.raspberrypi.org/en/projects/getting-started-with-picamera/4) control with Python.
- Live stream with [USB webcam on local browser](https://tutorials-raspberrypi.com/raspberry-pi-security-camera-livestream-setup/) or with [pi-camera](https://learn.adafruit.com/cloud-cam-connected-raspberry-pi-security-camera/adafruit-io), [pi-camera using motion](https://learn.adafruit.com/cloud-cam-connected-raspberry-pi-security-camera?view=all). Also see this for a wayaround 
- [rsync](https://www.raspberrypi.org/documentation/remote-access/ssh/rsync.md)
- [Servo moter](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-8-using-a-servo-motor)
- [Power Control](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-13-power-control)

## 4. Knowledge

### 4.1. Electrical Sensors

Che wrote:

- How do we communicate with sensors? clock
- How we process the data reading from sensors?
- Data log and plots.
- Initializing and calibration. [ZD] Temp: using a thermometer; Light intensity: ZD can borrow a professional one from lab; humidity: buy a professional one from Amazon?
- Camera-> [ZD] There are many camera modules for Raspberry Pi but not as many for Arduino (as far as I know...). So (1) use Raspberry Pi (2) search for more Arduino projects with camera; (3) search for adapters to connect Arduino and Raspberry Pi cameras.

### 4.2. WiFi modules

Che wrote:

- How do we achieve remote control and communication through WiFi? ->[ZD] For Raspberry Pi it is very straightforward as it has built-in WiFi module, for Arduino there are some modules based on the [ESP8266 microchip](https://en.wikipedia.org/wiki/ESP8266) such as Adafruit Feather HUZZAH (I have this!, read manual [here](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266)) or [SparkFun ESP8266 Thing Dev Board](learn.sparkfun.com/tutorials/esp8266-thing-development-board-hookup-guide).

### 4.3. Programming on Hardware

Che wrote:

- Syntax of the programming language;
- Debug and tests scheme.
- Development tools.

### 4.4. DIY

ZD:

- chamber (Should have enough insulation for heat)
- plates for growing Arabidopsis
- scaffolds to mount sensors

Che wrote:

- 3D printing and CAD models.
- Robotic arms

## 5. Papers

1. Jolles, J. Broad-scale Applications of the Raspberry Pi: A Review and Guide for Biologists. https://ecoevorxiv.org/qh9sz/ (2021) doi:10.32942/osf.io/qh9sz.
1. Tausen, M. et al. Greenotyper: Image-Based Plant Phenotyping Using Distributed Computing and Deep Learning. Front. Plant Sci. 11, (2020).
1. Gaggion, N. et al. ChronoRoot: High-throughput phenotyping by deep segmentation networks reveals novel temporal parameters of plant root system architecture. bioRxiv 2020.10.27.350553 (2020) doi:10.1101/2020.10.27.350553.
