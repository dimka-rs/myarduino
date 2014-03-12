// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int pos = 0;    // variable to store the servo position 
int diff = 10;

void setup() 
{ 
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
//  Serial.begin(9600);
} 
 
void set(int pos) {
  myservo.write(pos);
//  Serial.print(pos);
//  Serial.print("\r");
  delay(20);

}
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)
  {
    set(pos);
  }

  for(pos = 180; pos > 0; pos -= 1)
  {
    set(pos);
  } 
} 
