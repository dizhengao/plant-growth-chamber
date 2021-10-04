#include <SoftwareSerial.h>
#include "Sensors.h"

NTC_temp::NTC_temp () {
  PIN = NTC_ANALOG_PIN;
}

NTC_temp::NTC_temp (int pin) {
  PIN = pin;
}



float NTC_temp::read_ntc_sensor_temp(){
  float Temp_NTC_sensor=0.0; // the temperature reading from the NTC sensore
  int R0=10000;
  int B_parameter=3950;
  int T0=25;
  
  int NUMSAMPLES=5;
  int samples[NUMSAMPLES];
  float average;
  uint8_t i;
  
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(PIN);
   delay(10);
  }
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;

  
  // convert the value to resistance
  //average = 1023 / average - 1;
  //average = R0 / average;

  
  float steinhart;
  // convert the value to resistance
  average = average/1023;
  steinhart=average*R0/(1-average);
  steinhart=log(steinhart/R0);
  
  //steinhart = average / R0;     // (R/Ro)
  //steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= B_parameter;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (T0 + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert absolute temp to C
  
  return steinhart;
}
