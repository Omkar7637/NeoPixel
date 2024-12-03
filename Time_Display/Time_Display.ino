//  Project Name : Neo Pixel 


#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include <FastLED_NeoMatrix.h>
#include <FastLED.h>

#include <Wire.h>
#include <DS1307.h>

DS1307 rtc;
/*

#ifndef PSTR
 #define PSTR 
#endif
*/
#define PIN 12


#define mw 20
#define mh 15



// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(20, 15, PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800); // changes--> LEFT, ZIGZAG,ROWS

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup()
{
  //only set the date+time one time
//  rtc.set(0, 17, 2, 15, 10, 2022); //08:00:00 24.12.2014 //sec, min, hour, day, month, year

//  Serial.begin(9600);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(100);
  matrix.setTextColor(colors[0]);
    rtc.start();
}

int x    = matrix.width();
int pass=1;

void loop() 
{
//  rolling_message();
  read_time();

  
}
//======================== Rolling Message Routine ===================================
void rolling_message()
{
  matrix.fillScreen(0);
  matrix.setCursor(x, 3);
//  matrix.print(F("OMKAR Kashid"));
  matrix.print(F("WELCOME TO MODERN COLLEGE OF ENGINEERING, E&TC DEPARTMENT"));

 
 if(--x < -356) 
  {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }

  matrix.show();
  delay(150);
  
}
//========================= Clock display Routine ==================================

void read_time()
{
  uint8_t sec, min, hour, day, month,h;
  uint16_t year; 
   
  rtc.get(&sec, &min, &hour, &day, &month, &year);  //get time from RTC
  
  h=hour % 12 ;
  if(h == 0) { h=12;}

  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  if(h<9) { matrix.print("0"); }
  matrix.print((h));
  matrix.print(":");
  matrix.setTextColor(colors[1]);
  matrix.show();

  matrix.setCursor(0, 8);
  if(min<9) { matrix.print("0"); }
  matrix.print((min));
  matrix.setTextColor(colors[2]);
  matrix.show();
  delay(5000);
}
//============================= Test each LED ======================================
