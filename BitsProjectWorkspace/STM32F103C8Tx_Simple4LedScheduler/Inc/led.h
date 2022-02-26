/**
 ******************************************************************************
 * @file led.h
 * @date Feb 23, 2022
 * @author Kunal Verma
 * @details This file contains macros and function declarations for led.c
 ******************************************************************************
 */

#ifndef LED_H_
#define LED_H_

#define LED_PINB12   12
#define LED_PINB13   13
#define LED_PINB14   14
#define LED_PINB15   15

#define DELAY_COUNT_1MS 		200U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_100MS       (100U  * DELAY_COUNT_1MS)


void led_init_all(void);
void led_on(uint8_t led_no);
void led_off(uint8_t led_no);
void delay(uint32_t count);

#endif /* LED_H_ */
