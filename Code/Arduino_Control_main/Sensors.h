
// This header file for sensors used Bio-Maker 2021 projects
// Team member: W.Che and Z.Di.
// Date: 2021.03.22

#ifndef _Sensors_H
#define _Sensors_H
#include <Arduino.h>

#endif

#define NTC_ANALOG_PIN 0

class NTC_temp {
    int PIN;
    
  public:
    NTC_temp ();
    NTC_temp (int);
    float read_ntc_sensor_temp (void);
};
