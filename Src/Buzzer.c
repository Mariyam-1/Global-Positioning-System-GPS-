#include "../Inc/Buzzer.h"
void Buzzer_Init(void) {
    SYSCTL->RCGCGPIO |= 0x20;       // Enable Port F clock
    while((SYSCTL->PRGPIO & 0x20) == 0) {}; // Wait for ready
    GPIOF->DIR |= BUZZER_PIN;       // Set PF2 as output
    GPIOF->DEN |= BUZZER_PIN;       // Enable digital function
    GPIOF->DATA &= ~BUZZER_PIN;     // Turn off buzzer initially
}

void Buzzer_On(void) {
    GPIOF->DATA |= BUZZER_PIN;      // Turn on buzzer
}

void Buzzer_Off(void) {
    GPIOF->DATA &= ~BUZZER_PIN;     // Turn off buzzer
}
