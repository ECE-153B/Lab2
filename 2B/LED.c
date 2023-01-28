/*
 * ECE 153B - Winter 2021
 *
 * Name(s): Chris Fisher and Kenny Bui
 * Section: Tuesday
 * Lab: 2B
 */

#include "LED.h"

void LED_Init(void) {
	// Enable GPIO Clocks
	// [TODO]
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;        // Enable the Clock of GPIO Port A
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;        // Enable the Clock of GPIO Port C
	
	// Initialize Green LED
	// [TODO]
    GPIOA->MODER &= ~(GPIO_MODER_MODE5);                 // Clear bits 10 and 11 for Pin 5 
    GPIOA->MODER |= GPIO_MODER_MODE5_0;                  // Set bit 10, set Pin 5 as output to make it Output Mode

    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5);                 // Clear bit 5

	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5;					 // Set to No Pull Up, No Pull Down
}

void Green_LED_Off(void) {
	// [TODO]
	GPIOA->ODR &= ~(GPIO_ODR_OD5);
}

void Green_LED_On(void) {
	// [TODO]
	GPIOA->ODR |= GPIO_ODR_OD5;
}

void Green_LED_Toggle(void) {
	// [TODO]
	GPIOA->ODR ^= GPIO_ODR_OD5;
}
