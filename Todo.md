# Todo list

## Workflow

This is to clarify priority.

Last update: 5.4.21

0. [x] [Application](#application-done) and first-month 'report'
1. [x] [Che]Sensors assembly: Seeed thermo&humidity sensor, light sensor.
2. [ ] [Che]Temperature and light control.
3. [x] [Debug]Data logging: 
   1. [x] Cloud 
   2. [ ] LCD screen.
4. [ ] [Debug]3D-print plates.
5. [x] Camera.
6. [x] Data visualization on the 2nd Pi
   1. [x] real-time images, sensor data
   2. [ ] remote control.
7. [ ] Chamber assembly, circuit position into the chamber, light and camera ready.

## Meetings

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
| May        | More robust Environment control                      | ??        | ??    |

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
