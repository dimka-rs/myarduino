#include <Wire.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

Servo myservoX;
Servo myservoY;

int posx = 100;
int posy = 100;
float sumx = 0;
float sumy = 0;
float diffx = 0;
float diffy = 0;
const int MINX = 50;
const int MAXX = 150;
const int STEPX = 1;
const int MINY = 50;
const int MAXY = 150;
const int STEPY = 1;
const int DELAY = 5;
const int CYCLES = 5;
const float DEADZ = 0.5;
const float SETX = 0;
const float SETY = 0;

void setup() 
{ 
  myservoX.attach(9);
  myservoY.attach(8);
  
  Serial.begin(9600);
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
} 
 
 
void loop() 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
 
  sumx = 0;
  sumy = 0;
  delay(10); // let servos stop
  for (int i = 0; i < CYCLES; i++) {
    delay(DELAY);
    sumx += event.acceleration.x;
    sumy += event.acceleration.y;
  }
  sumx =  sumx/CYCLES;
  sumy =  sumy/CYCLES;
  
  diffx = SETX - sumx;
  if (abs(diffx) > DEADZ) {
    posx -= int(diffx*1);
    if (posx < MINX) {
      posx = MINX;
    }
/*    if (posx > MAXX) {
      posx = MAXX;
    }*/
    myservoX.write(posx);
  }
  diffy = SETY - sumy;
  if (abs(diffy) > DEADZ) {
    posy -= int(diffy*1);
    if (posy < MINY) {
      posy = MINY;
    }
/*    if (posy > MAXY) {
      posy = MAXY;
    }*/
    myservoY.write(posy);
  }
//  Serial.print("acc x="); Serial.print(sumx); Serial.print(", pos x="); Serial.print(posx);
//  Serial.print(", acc y="); Serial.print(sumy); Serial.print(", pos y="); Serial.println(posy);

}
