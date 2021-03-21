
#include <Wire.h>
#include <SoftwareSerial.h>

#include "RichUNOTM1637.h"
#include "RichUNOLM75.h"

// constants won't change. Used here to set a pin number:
const int NTC_Pin = A0;// the number of the NTC(temperature sensor) analog pin.
const int Water_level = A1; // the number of the waterlevel analog pin

LM75 temper;  // initialize an LM75 object "temper" for temperature


void setup() {
  
  Serial.begin(9600);
  Wire.begin();//you should run this function first, so that I2C device can use the I2C bus
  delay(1000);//
}

void loop() {
  // put your main code here, to run repeatedly:
  

  float Temp_LM75_built_in;
  float Temp_NTC_read;
  float Water_level;
  Temp_LM75_built_in = temper.getTemperatue();//get temperature
  Temp_NTC_read = read_ntc_sensor_temp();
  Water_level=read_water_sensro_level();
  
  Serial.print("Temp(LM75 Arduino Built in) "); 
  Serial.print(Temp_LM75_built_in);
  Serial.println(" *C");
  Serial.println("\n");
  Serial.print("Temp(NTC)"); 
  Serial.println(Temp_NTC_read);
  Serial.println(" *C");

  Serial.print("Water Height"); 
  Serial.println(Water_level);
  Serial.println(" mm");
  
  
  
}



float read_ntc_sensor_temp(){
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
   samples[i] = analogRead(NTC_Pin);
   delay(10);
  }
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;

  
  // convert the value to resistance
  average = 1023 / average - 1;
  average = R0 / average;
  
  float steinhart;
  steinhart = average / R0;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= B_parameter;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (T0 + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert absolute temp to C
  
  return steinhart;
}

float read_water_sensro_level(){
  int NUMSAMPLES=20;
  int samples[NUMSAMPLES];
  float average;
  uint8_t i;
  
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(Water_level);
   delay(10);
  }
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;

  average /= 1023.;

  float water_height;

  water_height = 24.0*(1.0-average);
  
  return water_height;

}
