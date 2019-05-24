# BNO055-test
calibration test for BNO055 sensor on Arduino IDE and UNO board 
* connect BNO055 via I2C pins on Arduino UNO
* requires Adafruit BNO055 library

To use:
* open serial console at 115200 baud
* rotate BNO055 by 90 deg on each axis until sys=3 (system ready)
* compass reading in degrees will show up, 0= magnetic north
