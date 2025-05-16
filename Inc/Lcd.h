#ifndef LCD_H
#define LCD_H
#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "SysTick.h"


#define LCD_PORT      GPIOB

// Control Pins
#define RS    (1U << 4)  // PB4
#define EN    (1U << 5)  // PB5
// RW pin is not used (tied to ground for write-only operation)

// Data Pins (PB0-PB3)
#define DATA_PINS 0x0F 
void LCD_Init(void);
void LCD_Command(uint8_t cmd);
void LCD_WriteChar(char data);
void LCD_PrintString(const char *str);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear(void);
void LCD_EnablePulse(void);

#endif
