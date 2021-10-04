
#include <Wire.h>
#include <SoftwareSerial.h>

#include "seeed_bme680.h" 
#include "RichUNOLM75.h" 
#include "Sensors.h" 
#include <multi_channel_relay.h>
#include "RichUNODS1307.h"

// bme680 sensor
#define IIC_ADDR  uint8_t(0x76)
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */
float BME_temp;
float BME_humi;
float BME_pressure;

// Arduino built in temperature sensor
LM75 temper75;  // initialize an LM75 object "temper" for temperature


// analog sensors of the Arduino sensors, including: NTC sensors.
#define NTC_Pin A0;
NTC_temp temperNTC(0);//Define input pin for NTC sensors, calculate the correct sensor reading
float Temp_LM75_built_in;
float Temp_NTC_read;
// relay
Multi_Channel_Relay relay;
int Relay_status;
// macro to covert status to bit
#define BIT(n,i) (n>>i&1)

// Chamber Temperature
double ChamberTemp;

// Water system
unsigned long WaterStartTime;
unsigned long WaterCurrentTime;
bool WaterRunning;

// Time on Arduino Board
DS1307 clock;//define a object of DS1307 class
unsigned long LightFanStartTime;
unsigned long LightFanCurrentTime;
bool LightFanRun;

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

    // Set up the clock
    clock.begin();
    // Flag to show if the light fun is operating
    LightFanRun=1;
    LightFanStartTime=millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bme680.read_sensor_data()) {
        Serial.println("Failed to perform reading :(");
        return;
    }
    
    Temp_LM75_built_in = temper75.getTemperatue();//get temperature from LM75 sensor
    Temp_NTC_read = temperNTC.read_ntc_sensor_temp();// get temperature from NTC sensor

    BME_temp=bme680.sensor_result_value.temperature-4;
    BME_humi=bme680.sensor_result_value.humidity;
    BME_pressure=bme680.sensor_result_value.pressure / 1000.0;
 
    
    // Arduino Built in Temp
    Serial.print(Temp_LM75_built_in);
    Serial.print(",");
    
    // Bme Temp oC
    Serial.print(BME_temp);
    Serial.print(",");

    // NTC Temp 
    Serial.print(Temp_NTC_read);
    Serial.print(",");
     
    // Bme Pressure kPa
    Serial.print(BME_pressure);
    Serial.print(",");
    
    // Bme Humidity %
    Serial.print(BME_humi);
    Serial.print("\n");

    ChamberTemp=BME_temp;
    // Temperature fan control for the chamber
    // BIT(Relay_status,1) convert the status into binary number, the bit at 0 corresponds to switch 1.
    Relay_status=relay.getChannelState();
    if (BIT(Relay_status,3)!=1 && ChamberTemp > 26){
      relay.turn_on_channel(4);
    }

    if (BIT(Relay_status,3)==1 && ChamberTemp < 24){
      relay.turn_off_channel(4);
    }
    
    // Temperature heater control for the chamber
  if (BIT(Relay_status,2)==!1 && ChamberTemp < 20){
      relay.turn_on_channel(3);
    }
   if (BIT(Relay_status,2)==1 && ChamberTemp > 24){
      relay.turn_off_channel(3);
    }
    

    // Watering the system under command from PI

    if (Serial.available() > 0) {
    // read the incoming byte:
    String Command = Serial.readStringUntil('\n');
    if (Command=="water"){
      // turn on the relay switch 1
      relay.turn_on_channel(1);
      // Mark the water running status as on
      WaterRunning = 1;
      // record the watering start time
      WaterStartTime = millis();
    }
  }

  // Watering time count down
  if (WaterRunning==1){
    WaterCurrentTime=millis();
    if(WaterCurrentTime-WaterStartTime>=30000){
      relay.turn_off_channel(1);
      WaterRunning=0;
    }
  }
   clock.getTime();
   if (clock.hour>=0 && clock.hour<=8){
      if (LightFanRun==1){
        relay.turn_on_channel(2);
        LightFanRun=0;
      }   
   }
   else if(clock.minute%2==0){
        if (LightFanRun==0){
        relay.turn_off_channel(2);// turn on the light fan
        LightFanRun=1;
        }
   }
   else if(clock.minute%2==1){
        if (LightFanRun==1){
        relay.turn_on_channel(2);// turn off the light fan
        LightFanRun=0;
        }
    }
   
   
    delay(500);
}
