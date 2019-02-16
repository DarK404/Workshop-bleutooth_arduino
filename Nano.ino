#include <Servo.h>
#define ledPin 13
#define ledPin2 12
#define inA1 9
#define inA2 4
#define inB1 7
#define inB2 8
int ENA = 12;
int ENB = 10;
int state = 0;
Servo servo2;
int pos = 0 ;
Servo servo1 ;
int pos1 = 0 ;
void setup() {
  servo1.attach(8);
  servo2.attach(7);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);

  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state);
    digitalWrite(ENA, HIGH);
    digitalWrite(ENB, HIGH);
  }


  if (state == '7') {
    servo1.write(90);
    delay(1);
    state = 0;
  }


  if (state == '8') {
    servo1.write(0);
    delay(1);
    state = 0;
  }
  if (state == '9') {
    servo2.write(0);
    delay(1);
    state = 0;
  }
  if (state == '5') {
    servo2.write(60);
    delay(1);
    state = 0;
  }
  if (state == '1') {
    digitalWrite(inB1, HIGH);
    digitalWrite(inA1, HIGH);

    state = 0;
  }
  if (state == '2') {
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, HIGH);
    state = 0;
  }
  if (state == '3') {
    digitalWrite(inA1, HIGH);
    digitalWrite(inB2, HIGH);
    state = 0;
  }
  if (state == '4') {
    digitalWrite(inB1, HIGH);
    digitalWrite(inA2, HIGH);
    state = 0;
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(inA1, LOW);
    digitalWrite(inA2, LOW);
    digitalWrite(inB1, LOW);
    digitalWrite(inB2, LOW);
    state = 0;
  }

}
