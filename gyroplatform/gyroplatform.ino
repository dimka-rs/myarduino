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
const int MINX = 50;
const int MAXX = 150;
const int STEPX = 1;
const int MINY = 50;
const int MAXY = 150;
const int STEPY = 1;
const float DEADZ = 0.5;

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
 
  sumx = event.acceleration.x;
  sumy = event.acceleration.y;
  delay(50);
  sumx += event.acceleration.x;
  sumy += event.acceleration.y;
  delay(50);
  sumx += event.acceleration.x;
  sumy += event.acceleration.y;
  sumx =  sumx/3;
  sumy =  sumy/3;
  Serial.print("x="); Serial.print(sumx); Serial.print(", y="); Serial.println(sumy);
  
  if(sumx < -DEADZ) {
    if (posx > MINX) {
      posx -= STEPX;
      myservoX.write(posx);
      delay(15);
    }
  } else if (sumx > DEADZ) {
    if (posx < MAXX) {
      posx += STEPX;
      myservoX.write(posx);
      delay(15);
    }
  }

  if(sumy < -DEADZ) {
    if (posy > MINY) {
      posy -= STEPY;
      myservoY.write(posy);
      delay(15);
    }
  } else if (sumy > DEADZ){
    if (posy < MAXY) {
      posy += STEPY;
      myservoY.write(posy);
      delay(15);
    }
  }

}
