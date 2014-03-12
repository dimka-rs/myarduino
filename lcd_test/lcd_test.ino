//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
 
/*******************************************************
 
This program will test the LCD panel and the buttons
Mark Bramwell, July 2010
 
********************************************************/
 
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
// define some values used by the panel and buttons
int lcd_key     = 0;
unsigned int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

#define R1 16
#define R2 17
#define R3 18
#define R4 19
 
// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 lcd.setCursor(5,0);
 lcd.print("    ");
 lcd.setCursor(5,0);
 lcd.print(adc_key_in);
 lcd.setCursor(0,1);            // move to the begining of the second line
 if (adc_key_in > 1000) return btnNONE;
 if (adc_key_in < 50)   return btnRIGHT;  //0
 if (adc_key_in < 200)  return btnUP; //99
 if (adc_key_in < 400)  return btnDOWN; //255
 if (adc_key_in < 550)  return btnLEFT; //407
 if (adc_key_in < 800)  return btnSELECT;  //639
 
 return btnNONE;  // when all others fail, return this...
}
 
void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("ADC:"); // print a simple message
 pinMode(R1, OUTPUT);
 pinMode(R2, OUTPUT);
 pinMode(R3, OUTPUT);
 pinMode(R4, OUTPUT);
}
  
void loop()
{
 lcd.setCursor(9,1);            // move cursor to second line "1" and 9 spaces over
 lcd.print(millis()/1000);      // display seconds elapsed since power-up
 
 
 lcd_key = read_LCD_buttons();  // read the buttons
 
 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     lcd.print("RIGHT ");
     digitalWrite(R4, HIGH);     
     break;
     }
   case btnLEFT:
     {
     lcd.print("LEFT   ");
     digitalWrite(R2, HIGH);
     break;
     }
   case btnUP:
     {
     lcd.print("UP    ");
     break;
     }
   case btnDOWN:
     {
     lcd.print("DOWN  ");
     digitalWrite(R3, HIGH);
     break;
     }
   case btnSELECT:
     {
     lcd.print("SELECT");
     digitalWrite(R1, HIGH);
     break;
     }
     case btnNONE:
     {
     lcd.print("NONE  ");
     digitalWrite(R1, LOW);
     digitalWrite(R2, LOW);
     digitalWrite(R3, LOW);
     digitalWrite(R4, LOW);
     break;
     }
 }
 
}
