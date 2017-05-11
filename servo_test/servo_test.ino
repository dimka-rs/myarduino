#include <Wire.h>
#include <Servo.h>

Servo myservo10;
Servo myservo11;
Servo myservo12;
Servo myservo13;

void setup() 
{ 
  myservo10.attach(10);
  myservo11.attach(11);
  myservo12.attach(12);
  myservo13.attach(13);
  Serial.begin(115200);
  Serial.print("Start\n");
} 

void loop()
{
  for (int i=0; i<=180; i++) {
  myservo10.write(i);
  myservo11.write(i);
  myservo12.write(i);
  myservo13.write(i);
  Serial.print(i);
  Serial.print("\n");
  delay(100);
  }
  for (int i=180; i>=0; i--) {
  myservo10.write(i);
  myservo11.write(i);
  myservo12.write(i);
  myservo13.write(i);
  Serial.print(i);
  Serial.print("\n");
  delay(100);
  }
}
