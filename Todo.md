# Todo list

## Urgent

- [ ] A new plate and a presser

## Workflow

This is to clarify priority.

Last update: 27.4.21

0. [x] [Application](#application-done) and first-month 'report'
1. [x] [Che]Sensors assembly: Seeed thermo&humidity sensor, light sensor.
2. [ ] [Che]Temperature and light control.
3. [x] [Debug]Data logging: 
   1. [x] Cloud 
   2. [ ] LCD screen.
4. [x] [Debug]3D-print plates.
5. [x] Camera.
6. [x] Data visualization on the 2nd Pi
   1. [x] real-time images, sensor data
   2. [ ] remote control.
7. [x] Chamber assembly, circuit position into the chamber, light and camera ready.

## Meetings

### xx.6.21

**Aims:**

1. Implement fan, pump, humidifier. Position sensors.
2. Test cooling, temperature.

### 17.6.21

Install light and other device on the chamber. Simplify structure.

Todo:

1. Need to change Relay program (Position; Always on for the top fan)
2. Implement fan, pump and sensor in the next week.

### 3.6.2021

**Aims:**

0. [x] Plot condition data and combine images into a video.
2. [x] Discuss achievement and problems in the first trial, summaries a .md to Trial folder.
	1. Features achieved 
	2. [x] Network connection problems -> split into two codes
	3. [x] Drain: See below
3. [x] Temperature calibration
4. [x] Cooling.
5. [x] Humidity control.
6. [x] Light.
7. [x] Irrigation:
   1. [ ] Intervals: 60h
   2. [ ] watering time: 30->15s
   3. [ ] How to drain remaining water? -> Hole at the bottom
8. [x] Visualisation kit
9. [ ] Next step plans (June):
	4. Controls
	5. modification to box
	6. LCD screen.
	7. Plate 2.0
	8. Irrigation

**Minutes:**

1. To summarise features and problems in the first trial.
2. [ ] Separate Rpi program into 2 python scripts: local logging and upload:
   1. [ ] two ssh sessions
   2. [ ] two .py
3. Cooling:
   1. Fan at the light
   2. Make two holes on the sides of the box, one for air in and another one for air out (with the help with a fan)
4. Irrigation:
   1. Drain a series of holes, with different sizes, at the bottom of the box and test the optimal size
   2. A tray under the lunch box to store extra water, make a holder (Tokenm) to hold the lunch on top of the tray.
   3. With the above, optimise irrigation intervals and duration.
   4. Add a manual control to pump
5. Temperature measurements: don't have to worry so much.
6. :sparkles:Make a portable visualisation kit.
7. Assemble a circuit to show BME680 and NTC values.

To buy:

1. Another fan
2. SD card
3. Cooler
4. Rpi and screen and card and case
5. Thermometer
6. Humidifier
7. Timer switch
8. Relay

### 17.4.2021

Aim:

- Assemble the chamber
- Temperature control, air circulation: fan, relay, heater.
- LCD screen for visualisation.
- [After] Order more hardware, especially light source.
- [After] Print the plate.

Minutes:

- Relay: able to drive fan. 
- But heater is not working.
- Water pump is running: i.e. water every 2 days, 30s each time. #TODO ZD needs to add serial-write to Main.py on Rpi.

## Time table

### Past

| Task Level | 16-22 Nov        | 23-29 Nov                        | 30-06 Dec        |
| ---------- | ---------------- | -------------------------------- | ---------------- |
| Primary    | Github work flow | Look for people and setup design | Application ddl! |

### On-going

| Task Level | Primary                                         | Secondary | Minor |
| ---------- | ----------------------------------------------- | --------- | ----- |
| March      | Sensors                                         | Controls  | ??    |
| Apr        | Growth condition control (Temp,Hum,Light,Water) | ??        | ??    |
| May        | Environment control                      | Light,LCD,remote controls        | ??    |

## April report

Prototype:

1. Chamber assembly
2. Sensors and environment controls
3. Webserver
4. Update Hackstor.

## Application (Done)

Things to prepare and decide:
Che wrote:

- Plan for the project: for the application use and project management.
- Learning from other projects: ongoing.
- Coding method: adurino IDE or XOD or Others.
- Chamber Dimension: What size should it be?
- Sensors: a draft plan like how many sensors? where to put them?
- Actuators: Lights---what wavelenghth?; Water Pump; Robotic Arms---What function we want to achieve with them.
- Flow Chart: Basic logic to link sensors and actuators. To illustrate how things work.

## To learn

Last update: 18.3.21

- [x] Arduino-Pi communication (UART)
- [x] XOD
- [ ] electromechanical relay
- [ ] Voltage divider
