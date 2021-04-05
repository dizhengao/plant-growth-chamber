
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
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  if (bme680.read_sensor_data()) {
        Serial.println("Failed to perform reading :(");
        return;
    }
    Serial.print("temperature ===>> ");
    Serial.print(bme680.sensor_result_value.temperature);
    Serial.println(" C");

    Serial.print("pressure ===>> ");
    Serial.print(bme680.sensor_result_value.pressure / 1000.0);
    Serial.println(" KPa");

    Serial.print("humidity ===>> ");
    Serial.print(bme680.sensor_result_value.humidity);
    Serial.println(" %");

    Serial.println();
    Serial.println();

  float Temp_LM75_built_in;
  float Temp_NTC_read;
  float Water_level;
  Temp_LM75_built_in = temper75.getTemperatue();//get temperature from LM75 sensor
  Temp_NTC_read = temperNTC.read_ntc_sensor_temp();
  
  Serial.print("Temp(LM75 Arduino Built in) "); 
  Serial.print(Temp_LM75_built_in);
  Serial.println(" *C");
  Serial.println("\n");
  Serial.print("Temp(NTC)"); 
  Serial.println(Temp_NTC_read);
  Serial.println(" *C");

  delay(2000);

}
