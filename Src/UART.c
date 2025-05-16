#include "../Inc/UART.h"

char UART5_Read(void)
{
    while (UART5_FR_R & 0x10); 
    return (char)(UART5_DR_R & 0xFF);
}

void UART5_Write(char data)
{
    while (UART5_FR_R & 0x20); 
    UART5_DR_R = data;
}

void UART5_Init(void)
{
    SYSCTL_RCGCUART_R |= 0x20;     
    SYSCTL_RCGCGPIO_R |= 0x10;     
    while ((SYSCTL_PRGPIO_R & 0x10) == 0); 

    UART5_CTL_R &= ~0x01;           
    UART5_IBRD_R = 325;             
    UART5_FBRD_R = 35;              
    UART5_LCRH_R = 0x70;            

    GPIO_PORTE_AFSEL_R |= 0x30;    
    GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~0x00FF0000) | 0x00110000; 
    GPIO_PORTE_DEN_R |= 0x30;    
    GPIO_PORTE_DIR_R |= 0x20;     
    GPIO_PORTE_DIR_R &= ~0x10;    

    UART5_CTL_R |= 0x301;         
}
void UART5_ReceiveString(char *buffer, char terminator) {
    char c;
    int i = 0;

    while (1) {
        c = UART5_Read();
        if (c == terminator || i >= 99) break; // Prevent buffer overflow
        buffer[i++] = c;
    }
    buffer[i] = '\0'; 
}



void UART0_Init(void) {
    SYSCTL_RCGCUART_R |= 0x01;    
    SYSCTL_RCGCGPIO_R |= 0x01;    
    while ((SYSCTL_PRGPIO_R & 0x01) == 0); 

    UART0_CTL_R &= ~0x01;        

    // Baud rate = 9600 for 16MHz system clock
    UART0_IBRD_R = 104;           
    UART0_FBRD_R = 11;            
    UART0_LCRH_R = 0x70;          
    UART0_CTL_R = 0x301;          

    GPIO_PORTA_AFSEL_R |= 0x03;   
    GPIO_PORTA_PCTL_R &= ~0x000000FF;
    GPIO_PORTA_PCTL_R |= 0x00000011; 
    GPIO_PORTA_DEN_R |= 0x03;    
    GPIO_PORTA_AMSEL_R &= ~0x03; 
}

void UART0_Transmit(char data) {
    while (UART0_FR_R & 0x20);    
    UART0_DR_R = data;
}

char UART0_Receive(void) {
    while (UART0_FR_R & 0x10);    // Wait until RXFE is 0 (not empty)
    return (char)(UART0_DR_R & 0xFF);
}

void UART0_TransmitString(const char* str) {
    while (*str != '\0') {
        UART0_Transmit(*str++);
    }
}

void UART0_ReceiveString(char *buffer, char terminator) {
    char c;
    int i = 0;

    while (1) {
        c = UART0_Receive();
        if (c == terminator || i >= 99) break; // Prevent overflow
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

