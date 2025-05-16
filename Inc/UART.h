#ifndef UART_H
#define UART_H
#include "define.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"
char UART5_Read(void);
void UART5_Write(char data);
void UART5_Init(void);
void UART5_ReceiveString(char *buffer, char terminator) ;
void UART0_Init(void);

void UART0_Transmit(char data) ;
char UART0_Receive(void) ;
void UART0_TransmitString(const char* str) ;
void UART0_ReceiveString(char *buffer, char terminator) ;


#endif





















/*#ifndef UART_HEADER
#define UART_HEADER

#include "tm4c123gh6pm.h" // Header file accesses registers in TMC123 microcontroller
#include "define.h"
#include "Bitwise.h"

void UART0_Init(void);
void UART0_Transmit(char data);
char UART0_Receive(void);
void UART0_Control(char operation, char data);
void UART0_ReceiveString(char *buffer, char terminator);

void UART5_Init(void) ;
void UART5_Transmit(char data);
char UART5_Receive(void);
void UART5_TransmitString(const char* str);
void UART5_ReceiveString(char *buffer, char terminator);
#endif*/

