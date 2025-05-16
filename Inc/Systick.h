#ifndef SYSTICK_H
#define SYSTICK_H
#include "STD.h"
#include "tm4c123gh6pm.h"
#include "Bitwise.h"
#include "define.h"


static u32 systick_clock_hz =50000000;

void SysTick_Init(u32 clock_hz);
void SysTick_DelayMs(u32 ms);
void SysTick_DelayUs(u32 us);

#endif
