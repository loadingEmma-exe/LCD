#ifndef LCD_H
#define LCD_H

#include <mbed.h>

//function to toggle/pulse the enable bit
void toggle_enable(void);

//function to initialize the LCD
void LCD_init(void);

//function to display characters
void display_to_LCD(char value);
#endif