/*
 * main.c
 *
 *  Created on: Jun 14, 2022
 *      Author: badrm
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "sng.h"

u16 u16SampleCnt = 0;
void voidSetDAC();
int main()
{
	/* HSE Crystal Clock */
	RCC_voidInitSysClock();
	/* Enable Clock on GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
	/* Set pins from 0 to 7 to output PP 2MHZ */
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_FREQ_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_FREQ_2MHZ_PP);
	/* enable AHB/8 Clock on SYSTICK */
	MSTK_voidInit();
	/*
	 * We set interval periodically every 125 microsecond because 8 KHZ is used so every 1 second
	 * requires 8000 samples so 1/8000 = 125, each 125 microsecond ISR should be called to output
	 * the sample
	 */
	MSTK_voidSetIntervalPeriodic(125, voidSetDAC);

	while(1);


}
/* This function is sent to ISR to output each sample every 125 microseconds */
void voidSetDAC(){
	u8 i;
	for(i=0 ; i<8 ; i++){
		MGPIO_voidSetPinValue(GPIOA, i, GET_BIT(wemalo_raw[u16SampleCnt],i));
	}
	u16SampleCnt++;
	if(u16SampleCnt == 39474)
	{
		u16SampleCnt = 0;
	}
}
