#ifndef GPIO_HEADER
#define GPIO_HEADER

#include "tm4c123gh6pm.h" // Header file accesses registers in TMC123 microcontroller
#include "define.h"
#include "Bitwise.h"

#define GPIO_SW1 0x10
#define GPIO_SW2 0x1

#define GPIO_RED_LED 0x2
#define GPIO_BLUE_LED 0x4
#define GPIO_GREEN_LED 0x8

#define GPIO_LED_OFF 0
#define GPIO_LED_ON 1

#define Lock_Key 0x4C4F434B;

void PORTF_Init();
unsigned char GPIO_getSwitches(unsigned char sw);
void GPIO_setLeds(unsigned char ledColor, unsigned char ledState);
#endif

