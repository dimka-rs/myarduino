//http://overskill.alexshu.com/cheaphack-a-2-5-chinese-mp3-player-for-its-128x64-mini-lcd/

#include "U8glib.h"
U8GLIB_MINI12864 u8g(10, 9, 8); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RESET = 8
//U8GLIB_MINI12864 u8g(13, 11, 10, 9, 8); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RESET = 8
//U8GLIB_MINI12864_2X u8g(10, 9, 8); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RESET = 8
//U8GLIB_MINI12864_2X u8g(13, 11, 10, 9, 8); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, RESET = 8
void draw(void) {
 // graphic commands to redraw the complete screen should be placed here 
 u8g.setFont(u8g_font_unifont);
 //u8g.setFont(u8g_font_osb21);
 u8g.drawStr( 0, 22, "Hello World!");
 u8g.drawStr( 0, 42, "Ardiuno u8glib");
 u8g.drawStr( 0, 62, "Chinese MP3 LCD");
}
void setup(void) {
 u8g.setContrast(190);
}
void loop(void) {
 // picture loop
 u8g.firstPage(); 
 do {
 draw();
 } while( u8g.nextPage() );
 
 // rebuild the picture after some delay
 delay(50);
}
