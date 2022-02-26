/**
 ******************************************************************************
 * @file led.c
 * @date Feb 23, 2022
 * @author Kunal Verma
 * @details This file contains funtion definitions and
 *          led implementation of the project.
 ******************************************************************************
 */

#include<stdint.h>
#include "led.h"

void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init_all(void)
{
	uint32_t *pRccApb2enr = (uint32_t*)0x40021018;   //RCC APB-2 Clock Enable register
	*pRccApb2enr |= ( 1 << 3);  //To enable the clock of Port B

	uint32_t *pGpioBctrlRegH = (uint32_t*)0x40010C04; //Port B Control Register High
	*pGpioBctrlRegH   &= 0x0000FFFF;
	*pGpioBctrlRegH   |= 0x22220000;

	uint32_t *pGpioBModeReg = (uint32_t*)0x40010C0C; // GPIO Port B Output Data Register
	*pGpioBModeReg |= ( 1 << LED_PINB12);
	*pGpioBModeReg |= ( 1 << LED_PINB13);
	*pGpioBModeReg |= ( 1 << LED_PINB14);
	*pGpioBModeReg |= ( 1 << LED_PINB15);



#if 0
	//configure the outputtype
	*pGpioOpTypeReg |= ( 1 << (2 * LED_GREEN));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_RED));
	*pGpioOpTypeReg |= ( 1 << (2 * LED_BLUE));
#endif

	led_off(LED_PINB12);
	led_off(LED_PINB13);
	led_off(LED_PINB14);
	led_off(LED_PINB15);
}

void led_on(uint8_t led_no)
{
  uint32_t *pGpioB_DataReg = (uint32_t*)0x40010C0C;
  *pGpioB_DataReg |= ( 1 << led_no);
}

void led_off(uint8_t led_no)
{
	  uint32_t *pGpioB_DataReg = (uint32_t*)0x40010C0C;
	  *pGpioB_DataReg &= ~( 1 << led_no);
}
