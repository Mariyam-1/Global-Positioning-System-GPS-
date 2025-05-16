#include "../Inc/LCD.h"

void LCD_EnablePulse(void) {
    LCD_PORT->DATA |= EN;
    SysTick_DelayUs(1);
    LCD_PORT->DATA &= ~EN;
    SysTick_DelayUs(50);
}

void LCD_Send4Bits(uint8_t data) {
    LCD_PORT->DATA = (LCD_PORT->DATA & ~DATA_PINS) | (data & DATA_PINS);
}

void LCD_Send(uint8_t data, uint8_t mode) {
    if(mode) LCD_PORT->DATA |= RS;
    else LCD_PORT->DATA &= ~RS;
    LCD_Send4Bits(data >> 4);
    LCD_EnablePulse();
    LCD_Send4Bits(data);
    LCD_EnablePulse();
}

void LCD_Command(uint8_t cmd) {
    LCD_Send(cmd, 0);
    if(cmd == 0x01 || cmd == 0x02) SysTick_DelayMs(2);
    else SysTick_DelayUs(50);
}

void LCD_WriteChar(char data) {
    LCD_Send(data, 1);
}

void LCD_PrintString(const char *str) {
    while(*str) LCD_WriteChar(*str++);
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x00 : 0x40;
    LCD_Command(0x80 | (address + col));
}

void LCD_Clear(void) {
    LCD_Command(0x01);
    SysTick_DelayMs(2);
}

void LCD_Init(void) {
    // Enable GPIOB Clock
    SYSCTL->RCGCGPIO |= (1U << 1);
    while((SYSCTL->PRGPIO & (1U << 1)) == 0);
    LCD_PORT->DIR |= (RS | EN | DATA_PINS);
    LCD_PORT->DEN |= (RS | EN | DATA_PINS);
    LCD_PORT->AFSEL &= ~(RS | EN | DATA_PINS);
    LCD_PORT->DR8R |= DATA_PINS; 
    SysTick_DelayMs(40);
    LCD_Send4Bits(0x03);
    LCD_EnablePulse();
    SysTick_DelayMs(5);
    LCD_Send4Bits(0x03);
    LCD_EnablePulse();
    SysTick_DelayUs(150);
    LCD_Send4Bits(0x03);
    LCD_EnablePulse();
    
    LCD_Send4Bits(0x02);
    LCD_EnablePulse();
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    
    LCD_Clear();
}
