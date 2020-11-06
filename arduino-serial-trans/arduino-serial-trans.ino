#include <HCSR04.h>

int triggerPin = 4;
int echoPin = 5;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
  Serial.begin(9600, SERIAL_8N1);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop () {

  // send datas for Raspberry Pi
  float distance = distanceSensor.measureDistanceCm();
  Serial.print(distance);
  char array1[] = {32, 99, 109, 10}; // Space,c,m,LF
  Serial.print(array1);
  delay(200);

  // receive datas to Raspberry Pi
  int receivedByte;
  if (Serial.available() > 0) {
    receivedByte = Serial.read();

    switch (receivedByte) {
      case 82 :
        digitalWrite(2, HIGH);
        delay(30);
        digitalWrite(2, LOW);
        break;
      case 89 :
        digitalWrite(3, HIGH);
        delay(30);
        digitalWrite(3, LOW);
        break;
    }
  }
}
