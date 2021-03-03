# Prototype

1. Box (box + plate for plants + lamp + fan + mount)
2. sensor (circut + data log)
3. Enviortnment Control (Temp + Light + humidity + irrigation).
4. WiFi module
5.  Cloud (website (heroku or github page or something)) and visulasition  
6.  Robotic arm
7.  [Thermal cameras](http://plantphenotyping.com/products/plantscreen-imaging-sensors/#fluorcam)
8.  [Fluorescence cameras](http://plantphenotyping.com/products/plantscreen-imaging-sensors/#fluorcam) for in-box CF imaging.

## Workflow

This is to clarify priority of doing things:

1. [1st month] Sensors assembly on Arduino: thermosensor, light sensor, humidity sensor (if we have that in kit). Basic circuit installed on a cardboard box or polystyrene box.
2. Arduino-Pi communication and data logging.
3. 3D-print plates (ZD).
4. Temperature and light control.
5. Camera.
6. Data visualization on the 2nd Pi: real-time images, sensor data, remote control.
7. Chamber assembly, circuit position into the chamber, light and camera ready.

## Chamber

[20210104-Che]

### Dimensions (cm)

| Plant growing board    | Arduino board        | Raspberry Pi          | 4D touch screen | Raspberry Pi Screen |
| ---------------------- | -------------------- | --------------------- | --------------- | ------------------- |
| $12\times7.3\times1.8$ | $16\times7.5\times3$ | $8.5\times5.5\times2$ | $9\times5$      |                     |

### Basic parameters

Temperature: 20-22oC  
Humidity: 60%  
Light intensity: 6000 Lum or 150-200 PPFD (Photosynthetic Photon Flux Density).  

### Sensor placement

Light sensor: near the growing board facing upward
Temperature sensor: on the wall
Humidity sensor: on the wall (how do we tell if the plant needs to be watered)

Camera: on the top of the chamber

Water pump: where to put it???

### Temperature control

Large polystyrene box +
[Heating elements](https://uk.rs-online.com/web/p/heating-elements/2995950/), [air circulation Fan](https://uk.rs-online.com/web/p/axial-fans/6688827/), [cooling fan](https://www.banggood.com/Geekcreit-12V-6A-DIY-Electronic-Semiconductor-Refrigerator-Radiator-Cooling-Equipment-p-1074404.html?akmClientCountry=CN&cur_warehouse=CN), insulation panel

### Light

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

## Sensors [Ongoing]

### Temperature Sensor

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| NTC thermistors    | NO       |   [Steinhart-Hart equation](https://learn.adafruit.com/thermistor/using-a-thermistor) | Analog     | TBD|

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| LM75   | Yes (download library from bio-maker tutorial)       |   Read directly through I2C bus | Digital | TBD|

The two sensors agree with each other

### Light Sensor

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
|GL5528 photoresistor| NO      |  TBD  | Analog | TBD|

Analog sensor of low quality. Only roughly tells if the lights are bright enough. Can not be used for precise measurement.

### Humidity Sensor

Needs to buy one. Will check tomorrow.

### Data collection

Check out ThingSpeak(https://thingspeak.com) and some examples (https://community.thingspeak.com/tag/raspberry-pi/)
Not accurate and can not tell humidity. 

### LCD display

Address should be 20h (or 0x20), the document provided by the biomarker website is wrong.


[20210109 CHE]
Required equipment:
1. 多用电表
2.  temperature gauge for calibration
3.  lux meter???
