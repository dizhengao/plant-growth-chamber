
#include <Wire.h>
#include <SoftwareSerial.h>

#include "seeed_bme680.h" 
#include "RichUNOLM75.h" 
#include "Sensors.h" 
#include <multi_channel_relay.h>

// bme680 sensor
#define IIC_ADDR  uint8_t(0x76)
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */

// Arduino built in temperature sensor
LM75 temper75;  // initialize an LM75 object "temper" for temperature


// analog sensors of the Arduino sensors, including: NTC sensors.
#define NTC_Pin A0;
NTC_temp temperNTC(0);//Define input pin for NTC sensors, calculate the correct sensor reading

// relay
Multi_Channel_Relay relay;
int Relay_status;
// macro to covert status to bit
#define BIT(n,i) (n>>i&1)

// Water system
unsigned long StartTime;
unsigned long CurrentTime;
bool WaterRunning;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  while (!Serial);  
  while (!bme680.init()) {
        Serial.println("bme680 init failed ! can't find device!");
        delay(10000);
    }
    
    // Set up relay address
   relay.begin(0x11);

   //Flag to show if water is running
    WaterRunning=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bme680.read_sensor_data()) {
        Serial.println("Failed to perform reading :(");
        return;
    }


    
    float Temp_LM75_built_in;
    float Temp_NTC_read;
    
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

    // Temperature fan control
    // BIT(Relay_status,1) convert the status into binary number, the bit at 0 corresponds to switch 1.
    Relay_status=relay.getChannelState();
    if (BIT(Relay_status,1)!=1 && Temp_LM75_built_in > 35){
      relay.turn_on_channel(2);
    }

    if (BIT(Relay_status,1)==1 && Temp_LM75_built_in < 35){
      relay.turn_off_channel(2);
    }

    // Watering the system under command from PI

    if (Serial.available() > 0) {
    // read the incoming byte:
    String Command = Serial.readStringUntil('\n');
    if (Command=="water"){
      // turn on the relay switch 4
      relay.turn_on_channel(4);
      // Mark the water running status as on
      WaterRunning = 1;
      // record the watering start time
      StartTime = millis();
    }
  }

  // Watering time count down
  if ( BIT(Relay_status,3)==1 && WaterRunning==1){
    CurrentTime=millis();
    if(CurrentTime-StartTime>=10000){
      relay.turn_off_channel(4);
      WaterRunning=0;
    }
  }
    delay(1000);
}
