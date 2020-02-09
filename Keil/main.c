#include "GPIO_STM32F10x.h"             // Keil::Device:GPIO
#include "stm32f10x.h"                  // Device header

void delay_ms(uint32_t ms);

int main(void){
	GPIO_PinConfigure(GPIOC,13,GPIO_OUT_PUSH_PULL,GPIO_MODE_OUT10MHZ);
	while(1){
		GPIO_PinWrite(GPIOC,13,0);
		delay_ms(500);
		GPIO_PinWrite(GPIOC,13,0);
		delay_ms(500);
	}
}

void delay_ms(uint32_t ms){
	for(uint32_t i = 0; i<ms; i++){
		for(volatile uint32_t j = 0; j<i; j++);
	}
}