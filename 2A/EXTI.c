/*
 * ECE 153B - Winter 2021
 *
 * Name(s): Chris Fisher
 * Section: Tuesday 7:00 - 10:00
 * Lab: 2A
 */

#include "EXTI.h"
#include "LED.h"

void EXTI_Init(void) {
    // Initialize User Button
    // [TODO]

    GPIOC->MODER &= ~(GPIO_MODER_MODE13);                 // Clear bits 26 and 27 for Pin 13 to make it Input Mode

    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD13;         // Clear bits 26 and 27 for Pin 13 to make it No Pull Up, No Pull Down
	
	// Configure SYSCFG EXTI
	// [TODO]
	
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13;
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

	// Configure EXTI Trigger
	// [TODO]

	EXTI->FTSR1 |= EXTI_FTSR1_FT13;

	// Enable EXTI
	// [TODO]
	
	EXTI->IMR1 |= EXTI_IMR1_IM13;

	// Configure and Enable in NVIC
	// [TODO]

	NVIC_EnableIRQ(EXTI15_10_IRQn);		
	NVIC_SetPriority(EXTI15_10_IRQn, 0);		
}

// [TODO] Write Interrupt Handlers (look in startup_stm32l476xx.s to find the 
// interrupt handler names that you should use)

void EXTI15_10_IRQHandler(void) {
	// Clear interrupt pending bit
	EXTI->PR1 |= EXTI_PR1_PIF13;


	// Define behavior that occurs when interrupt occurs
	Green_LED_Toggle();
}