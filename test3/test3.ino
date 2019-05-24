// test for calibration & mag north heading reading
// per datasheet, when sys=3, all 3 sensors are ready.

#include <Wire.h>              // I2C
#include <Adafruit_Sensor.h>   // Sensor Library
#include <Adafruit_BNO055.h>   // 9DOF Library (Library Modified)

// const
#define BNO055_SAMPLERATE_DELAY_MS (100)
  
// create device instance
Adafruit_BNO055 bno = Adafruit_BNO055(55);
sensors_event_t event;  
byte calSys ;                // Sys Status (0-3 value)
byte calGyro;
byte calAccel;
byte calMag; 


void setup() {
  Serial.begin(115200);  
  // Start the 9DOF sensor //
  if(!bno.begin()){
    Serial.print("BNO055 not detected");         // error
    while(1);
    }
  bno.setExtCrystalUse(true); // use ext cyrstal
  bno.setMode( bno.OPERATION_MODE_NDOF );    // Put into NDOF Mode
  delay(1000);
 }



void loop() {  
  bno.getCalibration(&calSys, &calGyro, &calAccel, &calMag); //get cal values 
  if (calSys ==3) {  // all sensors are ready. print current heading
    bno.getEvent(&event);  
    Serial.print("heading:");
    Serial.println(event.orientation.x);     
  }
  else {  // not ready, display value to help calibration, tilt on 3 axis for mag sensor
    Serial.print("sys:");
    Serial.print(calSys, DEC);
    Serial.print(" G:");
    Serial.print(calGyro, DEC);
    Serial.print(" A:");
    Serial.print(calAccel, DEC);
    Serial.print(" M:");
    Serial.print(calMag, DEC);  
    Serial.println("");
  }
  delay(BNO055_SAMPLERATE_DELAY_MS);  
}


