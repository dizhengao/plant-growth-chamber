# Prototype

## Workflow

This is to clarify priority of doing things:

1. [1st month] Sensors assembly on Arduino: thermosensor, light sensor, humidity sensor (if we have that in kit). Basic circuit installed on a cardboard box or polystyrene box.
2. 3D-print plates (ZD).
3. Temperature and light control. 
4. Arduino-Pi communication and data logging.
5. Camera.
6. Data visualization on the 2nd Pi: real-time images, sensor data, remote control.
7. Chamber assembly, circuit position into the chamber, light and camera ready.

## Chamber

[20210104-Che]

### Dimensions (cm)

| Plant growing board    | Arduino board        | Raspberry Pi          | 4D touch screen | Raspberry Pi Screen |
| ---------------------- | -------------------- | --------------------- | --------------- | ------------------- |
| $12\times7.3\times1.8$ | $16\times7.5\times3$ | $8.5\times5.5\times2$ | $9\times5$      |                     |

### Sensor placement

Light sensor: near the growing board facing upward
Temperature sensor: on the wall
Humidity sensor: on the wall (how do we tell if the plant needs to be watered)

Camera: on the top of the chamber

Water pump: where to put it???

### Temperature control

Large polystyrene box +
[Heating elements](https://uk.rs-online.com/web/p/heating-elements/2995950/), [air circulation Fan](https://uk.rs-online.com/web/p/axial-fans/6688827/), [cooling fan](https://www.banggood.com/Geekcreit-12V-6A-DIY-Electronic-Semiconductor-Refrigerator-Radiator-Cooling-Equipment-p-1074404.html?akmClientCountry=CN&cur_warehouse=CN), insulation panel



##Sensors [Ongoing]

### Temperature Sensor

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| NTC thermistors    | NO       |   [Steinhart-Hart equation](https://learn.adafruit.com/thermistor/using-a-thermistor) | Analog     | TBD|

| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
| LM75   | NO       |   Read directly through I2C bus | Digital | TBD|

Are the two sensors agree?

### Light Sensor
| Sensor Type| In XOD Library? | Physics(reading to Temp value)| Data Type |   Data Logging Method|
| ---------- | --------- | -------- | -------- | ----------- |
|GL5528 photoresistor| NO      |  TBD  | Analog | TBD|

I will try and see if I can find a nod representing the sensor on the XOD custom library web.

### Humidity Sensor
Needs to buy one. Will check tomorrow.


[20210109 CHE]
Required equipment:
1. 多用电表
2.  temperature gauge for calibration
3.  lux meter???


