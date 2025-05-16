#include "../Inc/Systick.h"
static u32 systick_clock_hz;

void SysTick_Init(u32 clock_hz) {
    systick_clock_hz = clock_hz;
    SysTick->CTRL = 0;                   
    SysTick->LOAD = 0x00FFFFFF;          
    SysTick->VAL = 0;                    
    SysTick->CTRL = 0x05;                
}

void SysTick_DelayUs(u32 us) {
    u32 ticks = (systick_clock_hz / 1000000) * us;
    SysTick->LOAD = ticks - 1;
    SysTick->VAL  = 0;
    while ((SysTick->CTRL & 0x00010000) == 0); 
}

void SysTick_DelayMs(u32 ms) {
    while (ms--) {
        SysTick_DelayUs(1000);
    }  
}
