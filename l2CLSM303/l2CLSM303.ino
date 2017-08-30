#include <Wire.h>
byte x_l = 0;
byte x_h = 0;
int x = 0;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
//  setHighResolutionMode();
  setSampleRate();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x19);
  Wire.write(0xA8);
  Wire.endTransmission();
  Wire.requestFrom(0x19, 2);
//  while(!Wire.available());
  x_l = Wire.read();
  x_h = Wire.read();
  x = (int) ((x_h << 8) | (x_l));
  Serial.println(x);
  delay(3);
}

void setHighResolutionMode() {
  Wire.beginTransmission(0x19);
  Wire.write(0x23);
  Wire.write(0x08);
  Wire.endTransmission();
}

void setSampleRate() {
  Wire.beginTransmission(0x19);
  Wire.write(0x20); //the register
  Wire.write(0x77); //what you want it to do
  Wire.endTransmission();
}
