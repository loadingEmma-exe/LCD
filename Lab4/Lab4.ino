#include <SPI.h>
#include <Wire.h>

#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define LOGO_WIDTH 8 // OLED display width, in pixels
#define LOGO_HEIGHT 8 // OLED display height, in pixels

#define LEFT 11 //Left LED connected to pin 11.
#define RIGHT 12 //Right LED connected to pin 12. 

//Color definitions
#define BLACK 0x000000
#define BLUE 0x0000FF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define YELLOW 0xFFFF00
#define WHITE 0xFFFFF

bool scrollDone = false; //Scroll check for text and bitmap.

byte LArrow[8] = { //Robot's left arrow sprite.
  0b00000000,
  0b00110000,
  0b00111100,
  0b01111110,
  0b00111100,
  0b00110000,
  0b00000000,
  0b00000000
};

byte RArrow[8] = { //Robot's right arrow sprite.
  0b00000000,
  0b00001100,
  0b00111100,
  0b01111110,
  0b00111100,
  0b00001100,
  0b00000000,
  0b00000000
};

byte Character[8] = { //Custom sprite.
  0b00100100,
  0b00100100,
  0b01011010,
  0b10100101,
  0b10000001,
  0b01000010,
  0b00111100,
  0b00000000
};

byte Empty[8] = { //Custom sprite.
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins). The pins for I2C are defined by the Wire-library.
// On an arduino UNO: A4(SDA), A5(SCL) On an arduino MEGA 2560: 20(SDA), 21(SCL)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void writetext(int x) { 
  String text = "Lab 4 by: Emma Raymond Austin Hoang";

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false); //Ensures the text does not wrap around to the second line of the OLCD display.
  display.setCursor(x, 0);
  display.print(text);

}

void drawbitmap(int x) {
  int bitmapY = 32;

  display.drawBitmap(x, bitmapY, Character, 8, 8, SSD1306_WHITE); //Draws custom sprite.
}


void setup() {
  //SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;); //Don't proceed, loop forever
  }

  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  display.clearDisplay();
  display.display();
}

void loop() {
  delay(300);
  String text = "Lab 4 by: Emma Raymond Austin Hoang";
  int textWidth = text.length() * 12;

  if(!scrollDone) //Scrolls text and sprite once.
    {
      for (int i = 0; i < SCREEN_WIDTH + textWidth + LOGO_WIDTH; i++) { //Repeatedly draws text and sprite across the screen.
      int textX = SCREEN_WIDTH - i;   // text moves left
      int bitmapX = i - LOGO_WIDTH;   // bitmap moves right

      display.clearDisplay();

      writetext(textX);   // Scroll text
      drawbitmap(bitmapX);   // Scroll sprite

      display.display();
      delay(0.5);
    }
    scrollDone = true; //Checks true, no longer scrolls.
  }

  display.clearDisplay();

  int bitmapIdleX = (SCREEN_WIDTH - LOGO_WIDTH) / 2; //Centers the bitmap on the xaxis.
  int bitmapIdleY = (SCREEN_HEIGHT - LOGO_HEIGHT) / 2; //Centers the bitmap on the y-axis

  display.drawBitmap(bitmapIdleX, bitmapIdleY, Character, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Idle sprite
  display.drawBitmap(120, bitmapIdleY, LArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's left arrow
  display.drawBitmap(4, bitmapIdleY, RArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's right arrow
  display.display();

  for(;;){
    delay(1000);
    display.clearDisplay();
    digitalWrite(LEFT, LOW);
    digitalWrite(RIGHT, LOW);
    display.display();

    delay(1000);

    display.drawBitmap(120, bitmapIdleY, LArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's left arrow
    display.drawBitmap(4, bitmapIdleY, RArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's right arrow
    digitalWrite(LEFT, HIGH);
    digitalWrite(RIGHT, HIGH);
    display.display();
  }

}
  /* Left blinker
  delay(1000);
  display.clearDisplay();
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  display.display();

  delay(1000);
  display.drawBitmap(120, bitmapIdleY, LArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's left arrow
  digitalWrite(LEFT, HIGH);
  display.display();
  /

  /* Right blinker
  delay(1000);
  display.clearDisplay();
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  display.display();

  delay(1000);
  display.drawBitmap(4, bitmapIdleY, RArrow, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Robot's right arrow
  digitalWrite(RIGHT, HIGH);
  display.display();
  /

  /* Idle - no blinkers active.
  delay(1000);
  display.clearDisplay();
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  display.drawBitmap(bitmapIdleX, bitmapIdleY, Character, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE); //Idle sprite
  display.display();
  /

  
  
