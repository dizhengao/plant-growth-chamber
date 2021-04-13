
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
  while (!Serial);  
  while (!bme680.init()) {
        Serial.println("bme680 init failed ! can't find device!");
        delay(10000);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    if (data == '1'){
      if (bme680.read_sensor_data()) {
        Serial.println("Failed to perform reading :(");
        return;
        }
       // Arduino Built in Temp LM75
      Serial.print(temper75.getTemperatue());
      Serial.print(",");
    
      // Bme Temp oC
      Serial.print(bme680.sensor_result_value.temperature);
      Serial.print(",");

      // NTC Temp 
      Serial.print(temperNTC.read_ntc_sensor_temp());
      Serial.print(",");
     
      // Bme Pressure kPa
      Serial.print(bme680.sensor_result_value.pressure / 1000.0);
      Serial.print(",");
    
      // Bme Humidity %
      Serial.print(bme680.sensor_result_value.humidity);
      Serial.print("\n");
    
      delay(1000);
    }
  }
}
