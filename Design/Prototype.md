# Prototype

1. Box (box + plate for plants + lamp + fan + mount)
2. sensor (circut + data log)
3. Enviortnment Control (Temp + Light + humidity + irrigation).
4. WiFi module
5.  Cloud (website (heroku or github page or something)) and visulasition  
6.  Robotic arm
7.  [Thermal cameras](http://plantphenotyping.com/products/plantscreen-imaging-sensors/#fluorcam)
8.  [Fluorescence cameras](http://plantphenotyping.com/products/plantscreen-imaging-sensors/#fluorcam) for in-box CF imaging.

- [Prototype](#prototype)
  - [1. Workflow](#1-workflow)
  - [2. Chamber](#2-chamber)
    - [2.1. Dimensions (cm)](#21-dimensions-cm)
    - [2.2. Basic parameters](#22-basic-parameters)
    - [2.3. Sensor placement](#23-sensor-placement)
    - [2.4. Temperature control](#24-temperature-control)
    - [2.5. Light](#25-light)
  - [3. Sensors [Ongoing]](#3-sensors-ongoing)
    - [3.1. Temperature Sensor](#31-temperature-sensor)
    - [3.2. Light Sensor](#32-light-sensor)
    - [3.3. Humidity Sensor](#33-humidity-sensor)
    - [3.4. Data collection](#34-data-collection)
    - [3.5. LCD display](#35-lcd-display)
    - [3.6. Camera](#36-camera)

## 1. Workflow

This is to clarify priority of doing things:

1. [Che]Sensors assembly: Seeed thermo&humidity sensor, light sensor.
2. [Che]Temperature and light control.
3. [Debug]Data logging: to cloud and LCD screen.
4. [Debug]3D-print plates.
5. Camera.
6. Data visualization on the 2nd Pi: real-time images, sensor data, remote control.
7. Chamber assembly, circuit position into the chamber, light and camera ready.

## 2. Chamber

[20210104-Che]

### 2.1. Dimensions (cm)

| Plant growing board    | Arduino board        | Raspberry Pi          | 4D touch screen | Raspberry Pi Screen |
| ---------------------- | -------------------- | --------------------- | --------------- | ------------------- |
| $12\times7.3\times1.8$ | $16\times7.5\times3$ | $8.5\times5.5\times2$ | $9\times5$      |                     |

### 2.2. Basic parameters

Temperature: 20-22oC  
Humidity: 60%  
Light intensity: 6000 Lum or 150-200 PPFD (Photosynthetic Photon Flux Density).  

### 2.3. Sensor placement

Light sensor: near the growing board facing upward
Temperature sensor: on the wall
Humidity sensor: on the wall (how do we tell if the plant needs to be watered)

Camera: on the top of the chamber

Water pump: where to put it???

### 2.4. Temperature control

Large polystyrene box +
[Heating elements](https://uk.rs-online.com/web/p/heating-elements/2995950/), [air circulation Fan](https://uk.rs-online.com/web/p/axial-fans/6688827/), [cooling fan](https://www.banggood.com/Geekcreit-12V-6A-DIY-Electronic-Semiconductor-Refrigerator-Radiator-Cooling-Equipment-p-1074404.html?akmClientCountry=CN&cur_warehouse=CN), insulation panel

### 2.5. Light

LED panels from Photon (Czech):
- [LED Fyto-Panels from Photon](http://led-growing-lights.com/products/led-fyto-panels/#downloads) - Very expensive
- [Compact LED Bars](http://led-growing-lights.com/products/led-bars/compact-led-bars/#details)- Very expensive. 
  - PPFD: max. 920 µmol.m-2.s-1 (at the distance of 50 cm)
  - Light source: 12 x 126 pcs. LED 5,700 K cool white
  - Compact LED Bars ( stand-alone system with standard powering option) 2,690 €
- [LED Lights SL 3500](http://led-growing-lights.com/products/led-lights-sl-3500/): The one used in Wanne's lab.
  - 20x20 cm RGB. Light emitting diodes (LEDs): 455 nm, 530 nm, 617 nm, cool white (4,500 - 10,000 K) and others
  -  High light output - up to 3,000 µmol.m-2.s-1 at the distance of 20 cm
  - £4,500 with a controller

## 3. Sensors [Ongoing]

### 3.1. Temperature Sensor

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| NTC thermistors    | NO       |   [Steinhart-Hart equation](https://learn.adafruit.com/thermistor/using-a-thermistor) | Analog     | TBD|

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| LM75   | Yes (download library from bio-maker tutorial)       |   Read directly through I2C bus | Digital | TBD|

The two sensors agree with each other

### 3.2. Light Sensor

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
|GL5528 photoresistor| NO      |  TBD  | Analog | TBD|

Analog sensor of low quality. Only roughly tells if the lights are bright enough. Can not be used for precise measurement.

### 3.3. Humidity Sensor

Needs to buy one. Will check tomorrow.

### 3.4. Data collection

Check out ThingSpeak(https://thingspeak.com) and some examples (https://community.thingspeak.com/tag/raspberry-pi/)
Not accurate and can not tell humidity. 

### 3.5. LCD display

Address should be 20h (or 0x20), the document provided by the biomarker website is wrong.

### 3.6. Camera

[Pi Camera](https://projects.raspberrypi.org/en/projects/getting-started-with-picamera/4) control with Python.

See full instruction on how to set up Raspberry pi camera [here](../Code/Raspi-Camera/instruction.md). Live stream can be viewed on adafruit IO's [feed](https://io.adafruit.com/Deebug/feeds/pi-camera) page.