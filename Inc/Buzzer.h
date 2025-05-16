#ifndef BUZZER_H
#define Buzzer_H
#include "define.h"
#include "tm4c123gh6pm.h"
#define BUZZER_DISTANCE 15 
#define BUZZER_PIN 0x04  
void Buzzer_Init(void) ;
void Buzzer_On(void) ;
void Buzzer_Off(void) ;
#endif
