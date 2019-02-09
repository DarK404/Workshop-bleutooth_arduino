int data = 0;
void setup() {
  Serial.begin(9600);
  digitalWrite(13, LOW);
  pinMode(13, OUTPUT);
}

void loop() {

  if (Serial.available() > 0)
  {
    int data = Serial.read();
    switch (data)
    {
      case '0':
        digitalWrite(13, HIGH);
        delay(10);
        break;
      case '1':
        digitalWrite(13, LOW);
        delay(10);
        break;
      default :
        break;
    }
    Serial.println(data);
  }
 
}
