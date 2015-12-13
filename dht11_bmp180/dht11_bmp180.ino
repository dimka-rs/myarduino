#include <dht11.h>
#include <Wire.h> 
#include <BMP085.h>

#define DHT11PIN 2

dht11 DHT11;
BMP085 dps = BMP085();
long Temperature = 0, Pressure = 0, Altitude = 0;

void setup()
{
  Serial.begin(115200);
//  Serial.println("DHT11 TEST PROGRAM ");
//  Serial.print("LIBRARY VERSION: ");
//  Serial.println(DHT11LIB_VERSION);
//  Serial.println();
  
  Wire.begin(); 
  delay(1000);
  dps.init();
}

void loop()
{

// DHT11: humidity temperature
  int chk = DHT11.read(DHT11PIN);
  switch (chk)
  {
    case DHTLIB_OK: 
//		Serial.println("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("Checksum error"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("Time out error"); 
		break;
    default: 
		Serial.println("Unknown error"); 
		break;
  }
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(" ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.print(" ");
  
//BMP180: temperature pressure altitude
  dps.getPressure(&Pressure); 
  dps.getTemperature(&Temperature);
  dps.getAltitude(&Altitude);
  Serial.print((long)Temperature*0.1);
  Serial.print(" ");
  Serial.print((long)Pressure/133.3);
  Serial.print(" ");
  Serial.println((long)Altitude);

  delay(60000);
}

