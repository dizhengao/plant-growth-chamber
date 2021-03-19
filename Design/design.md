# Design

This file is for general design ideas and resources to build the project.

- [Design](#design)
  - [1. Ideas](#1-ideas)
  - [2. Time table](#2-time-table)
    - [2.1. Pre-start](#21-pre-start)
    - [2.2. First month](#22-first-month)
    - [2.3. Final](#23-final)
  - [3. Reference](#3-reference)
    - [3.1. Suppliers](#31-suppliers)
    - [3.2. Some Hackster projects](#32-some-hackster-projects)
    - [3.3. Device](#33-device)
      - [3.3.1. Relay](#331-relay)
      - [3.3.2. WiFi](#332-wifi)
    - [3.4. XOD libraries](#34-xod-libraries)
      - [3.4.1. Hardware](#341-hardware)
      - [3.4.2. Basic XOD elements](#342-basic-xod-elements)
    - [3.5. Other references](#35-other-references)
    - [3.6. Questions:](#36-questions)

## 1. Ideas

quick thoughts can be added here

[20200303-ZD] Thermo cameras and fluorescence cameras. Also check out devices on [Photon](https://handheld.psi.cz/).

[20201203-ZD] To have another raspberry Pi with screen showing real time images and data logs, which can be put in home/lab bench so that you won't even have to have a computer to do the monitoring. It would be great if we have this along side with our prototype at the showcase event.

[20201125-Che] Lamp: Control RGB light separately; create different light intensity and RGB components for different experimental purposes.

[20201123-JMH] 1. Use robotic arm or something else to spray water from the top. This will be especially useful to water individual wells that are dried as a complement of watering from the bottom. 2. May include lime as CO2 scrubber to customize CO2 concentration for experiment purposes.

[20201115-ZD] Expand the prototype to larger scale: Use a robot with a camera to move around and take pictures of plants every xx minutes/hours; or install tracks for camera on the top of the chamber to take images every xx minute/hour.

## 2. Time table

### 2.1. Pre-start

| Task Level | 16-22 Nov        | 23-29 Nov                        | 30-06 Dec        |
| ---------- | ---------------- | -------------------------------- | ---------------- |
| Primary    | Github work flow | Look for people and setup design | Application ddl! |

### 2.2. First month

| Task Level | 07-20 Dec | 21-3 Jan | 4017 Jan | 18-31 Jan   |
| ---------- | --------- | -------- | -------- | ----------- |
| Primary    | xxx       | xxx      | xxx      | 29th report |

### 2.3. Final

| Task Level | Feb | Mar | Apr          |
| ---------- | --- | --- | ------------ |
| Primary    | xxx | xxx | Final report |

## 3. Reference

### 3.1. Suppliers

- [RS](https://uk.rs-online.com/web/)
- https://thepihut.com/
- https://shop.sb-components.co.uk/collections/raspberry-pi
- https://shop.pimoroni.com/
- https://www.okdo.com/
- https://uk.farnell.com/?pf_custSiteRedirect=true
- https://www.thorlabs.com/

### 3.2. Some Hackster projects

- :star:[FytoScope Chamber FS 130](http://growth-chambers.com/products/small-fytoscopes/fytoscope-chamber-130/#details) from Photon
- [Biomaker Tutorial](https://www.hackster.io/159756/biomaker-tutorial-1-getting-started-4fc966)
- :star:[Lunaflow](https://www.hackster.io/lunaflow/lunaflow-bioluminescent-plankton-for-3d-flow-visualisation-d60cbe): incubator design, **temperature control**, real-time monitor camera, codes.
- [Variable-Time Camera for Monitoring Plant Pollination Events](https://www.hackster.io/team-ppi/variable-time-camera-for-monitoring-plant-pollination-events-ad21e7) A **video and time-lapse monitor** to record pollinators interacting with plants. This project included an environmental sensor to measure temperature, humidity and barometric pressure and wrote this data into the image file names for later analysis.
- [Biofab Incubator](https://www.hackster.io/170194/biofab-incubator-6f5b0e) A low cost programmable incubator for growing mycelium textile. This project uses sensors to measure temperature and humidity and feeds this information back into the system to maintain constant environmental conditions.- [eCO-SENSE](https://www.hackster.io/glen-chua/eco-sense-soil-sensors-powered-by-plant-photosynthesis-be80a2) A sensor to monitor soil conditions powered by plant growth. This project uses a temperature sensor, moisture sensor and gas sensor to take measurements of soil 68 conditions and adds a bluetooth module to send the data wirelessly to a phone or computer.
- [Low Cost Oxygen Sensor for Bioreactors](https://www.hackster.io/biomaker/low-cost-oxygen-sensor-for-bioreactors-c7e066) This project developed a custom low-cost oxygen sensor to measure oxygen levels in cultures of E. coli, and logged the data via an Arduino microcontroller. 
- [A Behavioural Chamber to Evaluate Rodent Forelimb Grasping](https://www.hackster.io/alejandrocarn/a-behavioural-chamber-to-evaluate-rodent-forelimb-grasping-bedb1a) This project uses a light emitter and light sensor to monitor when a rodent moves past a certain threshold, and triggers release of a sugar pellet when it does. 

Refer to some plant growth products and facility that have been using in real plant research (e.g. in PGF) and [gardin](https://gard.in/) (This is very expensive so probably we won't use them in our project.)

### 3.3. Device

#### 3.3.1. Relay

- [Connecting a 12v 8 Channel Relay to an External Power Supply and RaspberryPi](https://medium.com/@jinky32/connecting-a-12v-8-channel-relay-to-an-external-power-supply-and-raspberrypi-6fec119c112c)  
- [Control High Voltage Devices with Arduino](https://howtomechatronics.com/tutorials/arduino/control-high-voltage-devices-arduino-relay-tutorial/)

#### 3.3.2. WiFi

Arduino there are some modules based on the [ESP8266 microchip](https://en.wikipedia.org/wiki/ESP8266) such as Adafruit Feather HUZZAH (I have this!, read manual [here](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266)) or [SparkFun ESP8266 Thing Dev Board](learn.sparkfun.com/tutorials/esp8266-thing-development-board-hookup-guide).

### 3.4. XOD libraries

#### 3.4.1. Hardware

*specific to Open-Smart Rich UNO R3 board:*

- Real time clock module: datetime (https://xod.io/libs/xod/datetime/) and ds-rtc (https://xod.io/libs/xod- dev/ds-rtc/) libraries.
- Onboard LM75 temperature sensor: lm75a-temp-sensor node can be found in the gst/lm75atempsensor XOD library.
- Onboard 4-digit display: tm1637-dev node from the cesars/tm1637 or cesars/tm1637-v2 library. This library also contains other nodes for onboard display, such as tm1637-decex, tm1637-autorange, tm1637-digits (for string)
- Various onboard modules: cesars/rich-uno-r3, cesars/utils (contains nodes required by the her other libraries)
- sd-log node: from xod/commonhardware library, for saving data into SD card.
- OLED screen: wayland/ssd1306-oled-i2c library. Nodes: ssd1306-oled-i2c-device

*Others*

- gweimer/utils

#### 3.4.2. Basic XOD elements

- Format number: *format-number* node
- *join* node

### 3.5. Other references

- [Robotic arm](https://shop.pimoroni.com/products/mearm-robot-raspberry-pi-kit?variant=21775370223699&currency=GBP&utm_source=google&utm_medium=cpc&utm_campaign=google+shopping?utm_source=google&utm_medium=surfaces&utm_campaign=shopping&gclid=Cj0KCQiA48j9BRC-ARIsAMQu3WTvhcmb-bZv5fxLHJMAYPL-1Bl-ShvdAIO8ML_nc9I4GpWhqUfcmDkaAn6uEALw_wcB), [Makeblock robot](https://www.makeblock.com/cn/mbot/)
- https://www.nature.com/articles/d41586-019-01590-z
- [Open-source lab](https://www.appropedia.org/Open-source_Lab)
- [BENEFICIAL BIO](https://beneficial.bio/)
- [Photon-plant phenotyping systems](http://plantphenotyping.com/)

### 3.6. Questions:

1. How to search XOD nodes? 
2. How to create our own nodes? And how hard/easy is this?
3. Devices using I2C protocol- How to find out their address? Does each of device come with different address or we can customize the add.?
4. What is DONE used for?