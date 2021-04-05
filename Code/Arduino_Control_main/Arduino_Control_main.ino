
#include <Wire.h>
#include <SoftwareSerial.h>

#include "seeed_bme680.h" // bme680 sensor

#define IIC_ADDR  uint8_t(0x76)
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */

#include "RichUNOLM75.h" // Arduino built in temperature sensor
LM75 temper75;  // initialize an LM75 object "temper" for temperature

#include "Sensors.h" // analog sensors of the Arduino sensors, including: NTC sensors.
#define NTC_Pin A0;
NTC_temp temperNTC(0);//Define input pin for NTC sensors, calculate the correct sensor reading

//Define output pin for temperature control: fan and heating elements. Think of the control flow

//Define output pin for control the water system




void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    float Temp_LM75_built_in;
    float Temp_NTC_read;
    float Water_level;
    Temp_LM75_built_in = temper75.getTemperatue();//get temperature from LM75 sensor
    Temp_NTC_read = temperNTC.read_ntc_sensor_temp();// get temperature from NTC sensor
 
    
    // Arduino Built in Temp
    Serial.print(Temp_LM75_built_in);
    Serial.print(",");
    
    // Bme Temp oC
    Serial.print(bme680.sensor_result_value.temperature);
    Serial.print(",");

    // NTC Temp 
    Serial.print(Temp_NTC_read);
    Serial.print(",");
     
    // Bme Pressure kPa
    Serial.print(bme680.sensor_result_value.pressure / 1000.0);
    Serial.print(",");
    
    // Bme Humidity %
    Serial.print(bme680.sensor_result_value.humidity);
    Serial.print("\n");
    
    delay(1000);
}
