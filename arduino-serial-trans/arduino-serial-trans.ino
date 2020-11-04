#include <HCSR04.h>

int triggerPin = 4;
int echoPin = 5;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
  Serial.begin(9600);
}
void loop () {
  double distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  delay(200);
}
