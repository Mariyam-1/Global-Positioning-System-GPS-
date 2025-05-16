#include "../Inc/GPIO.h"


void PORTF_Init(){
	 SYSCTL_RCGCGPIO_R |= 0x20;
  while (!(SYSCTL_RCGCGPIO_R & 0x20));

  GPIO_PORTF_LOCK_R = Lock_Key;
  setReg(GPIO_PORTF_CR_R,0x1F);
  clrReg(GPIO_PORTF_AMSEL_R,0x1F);
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
  clrReg(GPIO_PORTF_AFSEL_R ,0x1F);
	setReg( GPIO_PORTF_DIR_R, 0xE); //Leds directions are outputs
  clrReg(GPIO_PORTF_DIR_R ,0x11); //switches directions are input
  setReg(GPIO_PORTF_DEN_R,0x1F);  //Enable Digital Pins
  clrReg(GPIO_PORTF_DATA_R,0xE);
  setReg(GPIO_PORTF_PUR_R, 0x11);
}



unsigned char GPIO_getSwitches(unsigned char sw)
{
	switch (sw){
		case GPIO_SW1:
			return getBit(GPIO_PORTF_DATA_R ,4);
			break;
		case GPIO_SW2:
			return getBit(GPIO_PORTF_DATA_R ,0);
			break;
		
	}
}
void GPIO_setLeds(unsigned char ledColor, unsigned char ledState)
{
	switch (ledColor)
	{
		case GPIO_RED_LED:
			switch(ledState)
			{
				case GPIO_LED_OFF:
					clrBit(GPIO_PORTF_DATA_R ,1);
					break;
					case GPIO_LED_ON:
					setBit(GPIO_PORTF_DATA_R ,1);
					break;
					
			}break;
			case GPIO_BLUE_LED:
			switch(ledState)
			{
				case GPIO_LED_OFF:
					clrBit(GPIO_PORTF_DATA_R ,2);
					break;
					case GPIO_LED_ON:
					setBit(GPIO_PORTF_DATA_R ,2);
					break;
					
			}break;
			case GPIO_GREEN_LED:
			switch(ledState)
			{
				case GPIO_LED_OFF:
					clrBit(GPIO_PORTF_DATA_R ,3);
					break;
					case GPIO_LED_ON:
					setBit(GPIO_PORTF_DATA_R ,3);
					break;
					
			}break;
			
	}
		
}

