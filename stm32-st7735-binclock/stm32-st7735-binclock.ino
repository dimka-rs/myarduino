#include "SPI.h"
#include <Adafruit_GFX_AS.h>    // Core graphics library, with extra fonts.
#include <Adafruit_ILI9341_STM.h> // STM32 DMA Hardware-specific library

#define TFT_RST PA4
#define TFT_DC PA3
#define TFT_CS PA2
/*MOSI: PA7, SCK: PA6*/

#define DIG_SIZE 20
#define DIG_STEP 25
#define X_SHIFT 0
#define Y_SHIFT -30
#define COLS_GAP 7
#define TEXT_X 40
#define TEXT_Y 0

 
Adafruit_ILI9341_STM tft = Adafruit_ILI9341_STM(TFT_CS, TFT_DC, TFT_RST); // Use hardware SPI

uint8_t digits[] = {2,3,5,9,5,1}; //start value
uint8_t dig_max[] = {2,4,3,4,3,4}; //number of bits 
int w, h;
char init_time[] = __TIME__;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  w = tft.width();
  h = tft.height();
  //kinda stupid, but works...
  digits[0] = init_time[0]-'0';
  digits[1] = init_time[1]-'0';
  digits[2] = init_time[3]-'0';
  digits[3] = init_time[4]-'0';
  digits[4] = init_time[6]-'0';
  digits[5] = init_time[7]-'0';
}


void loop(void) {
  //time in text
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(TEXT_X, TEXT_Y);
  tft.setTextSize(2);
  tft.print(digits[0]);
  tft.print(digits[1]);
  tft.print(":");
  tft.print(digits[2]);
  tft.print(digits[3]);
  tft.print(":");
  tft.print(digits[4]);
  tft.print(digits[5]);

  
  //loop through digits
  for(int cnt=0; cnt < 6 ; cnt++) {
    digit(digits[cnt], dig_max[cnt], cnt*DIG_STEP+X_SHIFT+(cnt/2*COLS_GAP));
  }
  delay(1000);
  digits[5]++;
  if(digits[5] > 9) { digits[5]=0; digits[4]++; } //1 sec
  if(digits[4] > 5) { digits[4]=0; digits[3]++; } //10 sec
  if(digits[3] > 9) { digits[3]=0; digits[2]++; } //1 min
  if(digits[2] > 5) { digits[5]=0; digits[1]++; } //10 min
  if(digits[0] < 2) {
    if(digits[1] > 9) { digits[1]=0; digits[0]++; } //1 hour
  } else {
    if(digits[1] > 3) { digits[1]=0; digits[0]++; } //1 hour
  }
  if(digits[0] > 2) { for(int i = 0; i < 6;i++)digits[i]=0; } //10 hour
}

void digit(int value, int max, int pos) {
  for (int y = 0; y < max ; y++) {
      rect(pos, h+Y_SHIFT-y*DIG_STEP, DIG_SIZE, ILI9341_WHITE, value & (1 << y));
  }
}

void rect(int x, int y, int i, int color, int filled) {
  if (filled) {
    tft.fillRect(x+X_SHIFT, y, i, i, color);
  } else {
    tft.drawRect(x+X_SHIFT, y, i, i, color);
  }
  //tft.fillCircle(x, y, radius, color);
  //tft.drawCircle(x, y, radius, color);
}
