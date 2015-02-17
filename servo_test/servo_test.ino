#include <Wire.h>
#include <Servo.h>

Servo myservoX;
Servo myservoY;


void setup() 
{ 
  myservoX.attach(9);
  myservoY.attach(8);
 
} 

void loop()
{
  myservoX.write(90);
  myservoY.write(90);
}
