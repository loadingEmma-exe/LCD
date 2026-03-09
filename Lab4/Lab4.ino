#include <SPI.h>
#include <Wire.h>

#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define BLACK 0x000000
#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define CYAN 0x00FFFF
#define MAGENTA 0XFF00FF
#define YELLOW 0XFFFF00
#define WHITE 0XFFFFFF

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// byte LArrow = {
//   0b00110000,
//   0b00111100,
//   0b01111110,
//   0b00111100,
//   0b00110000
// }

// byte RArrow = {
//   0b00110000,
//   0b00111100,
//   0b01111110,
//   0b00111100,
//   0b00110000
// }

// byte Character = {
//   0b00100100,
//   0b00100100,
//   0b01011010,
//   0b10100101,
//   0b10000001,
//   0b01000010,
//   0b00111100
// }

void setup(){
  Serial.Begin(9600);
}

void loop(){

}

void main(void){
  LCD_init();
  display_to_LCD(0x48);
  display_to_LCD(0x45);
  display_to_LCD(0x4C);
  display_to_LCD(0x4C);
  display_to_LCD(0x4F);
}
