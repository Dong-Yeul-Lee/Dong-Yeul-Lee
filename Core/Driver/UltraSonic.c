/*
 * UltraSonic.c
 *
 *  Created on: Jan 7, 2022
 *      Author: 82102
 */
#include "UltraSonic.h"


uint16_t UltraSonicCounter;
uint8_t UltraSonicReadyFlag = 0;

void UltraSonic_SetCounter(uint16_t counter)
{
	UltraSonicCounter = counter;
}

uint16_t UltraSonic_GetCounter()
{
	return UltraSonicCounter;
}

void UltraSonic_SetReadyFlag(uint8_t flag) {
	UltraSonicReadyFlag = flag;
}

void UltraSonicTrigger() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
}

uint8_t UltraSonic_Is_Ready() {
	return UltraSonicReadyFlag;
}

uint16_t UltraSonic_GetDistance() {

	uint16_t distance;
	uint16_t counter = UltraSonic_GetCounter();

	UltraSonic_SetReadyFlag(CLEAR);

	distance = (int) (counter * 0.017);

	return distance;
}

void UltraSonic_ISR_Process() {
	uint16_t counter;

	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
		__HAL_TIM_SET_COUNTER(&htim2, 0);
	}
	else {
		counter = __HAL_TIM_GET_COUNTER(&htim2);
		UltraSonic_SetCounter(counter);
		UltraSonic_SetReadyFlag(READY);
	}
}
