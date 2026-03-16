#include <SPI.h>
#include <Wire.h>

#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Color definitions
#define BLACK 0x000000
#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFF

byte LArrow = {
  0b00110000,
  0b00111100,
  0b01111110,
  0b00111100,
  0b00110000
}

byte RArrow = {
  0b00110000,
  0b00111100,
  0b01111110,
  0b00111100,
  0b00110000
}

 byte Character = {
  0b00100100,
  0b00100100,
  0b01011010,
  0b10100101,
  0b10000001,
  0b01000010,
  0b00111100
}

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins). The pins for I2C are defined by the Wire-library.
// On an arduino UNO: A4(SDA), A5(SCL) On an arduino MEGA 2560: 20(SDA), 21(SCL)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawbitmap(void){
  display.clearDisplay();

  display.drawBitmap(
    (display.width() - LOGO_WIDTH) /2,
    (display.height() - LOGO_HEIGHT /2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display()
  delay(1000);
}

void writetext(void){
  display.clearDisplay();
  display.setTextSize(2); //Draw 2X-scale text
  display.setCursor(10,0);
  dispaly.printIn(F("scroll"));
  display.display(); //show initial text
  delay(1000);
}

void setup() {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen -- the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
  // Clear the buffer
  display.clearDisplay();
  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  // Show the display buffer on the screen. You MUST call display() after drawing commands to make them visible on screen!
  display.display();
}

void loop(){
  drawbitmap();
  writetext();
}

void main(void){
  LCD_init();
  display_to_LCD(0x48);
  display_to_LCD(0x45);
  display_to_LCD(0x4C);
  display_to_LCD(0x4C);
  display_to_LCD(0x4F);
}
