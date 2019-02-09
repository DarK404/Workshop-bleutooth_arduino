#include<SoftwareSerial.h>
int state=0;
void setup() {
  SoftwareSerial Serial(10, 11);
  Serial.begin(38400);
}
void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    Serial.print(Serial.read());
  } 
}
