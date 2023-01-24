/*
 * ECE 153B - Winter 2023
 *
 * Name(s):
 * Section:
 * Lab: 2C
 */
 
#include "stm32l476xx.h"

#include "LED.h"
#include "RTC.h"
#include "SysClock.h"

char strTime[12] = {0};
char strDate[12] = {0};

void RTC_Set_Alarm(void) {
	// [TODO]
}

void RTC_Alarm_Enable(void) {
	// [TODO]
	EXTI->RTSR1 |= EXTI_RTSR1_RT18;
	EXTI->IMR1 |= EXTI_IMR1_IM18;
	EXTI->EMR1 |= EXTI_EMR1_EM18;
	EXTI->PR1 |= EXTI_PR1_PIF18;
	NVIC_EnableIRQ(RTC_Alarm_IRQn);		
	NVIC_SetPriority(RTC_Alarm_IRQn, 0);
}

void RTC_Alarm_IRQHandler(void) {
	// [TODO]
	RTC_CR &= ~(RTC_CR_ALRAE); 			// Disable Alarm A
	RTC_CR &= ~(RTC_CR_ALRBE);			// Disable Alarm B
	RTC_CR &= ~(RTC_CR_ALRAIE);			// Disable Alarm A Interrupt
	RTC_CR &= ~(RTC_CR_ALRBIE);			// Disable Alarm B Interrupt
	RTC_Disable_Write_Protection();		// 

	while (RTC_ISR_ALRAWF == 0 && RTC_ISR_ALRBWF == 0) {

	}

	// --------------------------------------LEFT OFF HERE (Next do 2.c)--------------------------------------

}

int main(void) {	
	System_Clock_Init(); // Switch System Clock = 80 MHz
	
	LED_Init();
	
	RTC_Init();
	RTC_Alarm_Enable();
	RTC_Set_Alarm();
	
	while(1) {
		// [TODO]
	}
}
