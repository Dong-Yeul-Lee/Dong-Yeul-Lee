/*
 * buzzer.c
 *
 *  Created on: Dec 31, 2021
 *      Author: 82102
 */

#include "buzzer.h"

TIM_HandleTypeDef *hBuzzTim;
uint32_t buzzChannel;
uint16_t frequency_value = 500;

void BuzzerInit(TIM_HandleTypeDef *htim3, uint32_t channel) {
	hBuzzTim = htim3;
	buzzChannel = channel;
}

void BuzzerModeButtonSound() {
	/// make sound
	Buzzer_StartFreq();
	/// make freq
	Buzzer_GenFreq(frequency_value * 5);
	//  delay
	HAL_Delay(500);
	// make freq
//	Buzzer_GenFreq(frequency_value * 3);
//	// delay
//	HAL_Delay(500);
//	Buzzer_GenFreq(frequency_value * 1);
//	HAL_Delay(500);

	// sound off
	Buzzer_StopFreq();
}

void BuzzerSpeedButtonSound() {
	/// make sound
	Buzzer_StartFreq();
	/// make freq
	Buzzer_GenFreq(frequency_value * 1);
	//  delay
	HAL_Delay(500);
//	// make freq
//	Buzzer_GenFreq(frequency_value * 3);
//	// delay
//	HAL_Delay(500);
//	Buzzer_GenFreq(frequency_value * 5);
//	HAL_Delay(500);

	// sound off
	Buzzer_StopFreq();
}

void BuzzerEmergencySound() {

	Buzzer_StartFreq();
	Buzzer_GenFreq(frequency_value * 2);
	HAL_Delay(100);
	Buzzer_StopFreq();
}

void BuzzerTurnSignSound() {
	Buzzer_StartFreq();
	Buzzer_GenFreq(frequency_value * 3);
	//  delay
	HAL_Delay(100);
	// make freq
	Buzzer_StopFreq();

}

void Buzzer_StartFreq() {
	// PWM start ... 아래 변수부분은 하드코딩되어 고정인된다 추후 하드웨어가 바뀌는 경우 수정이 어렵기때문에 바꿔야한다.(&htim2, TIM_CHANNEL_1)

	HAL_TIM_PWM_Start(hBuzzTim, buzzChannel);
	/// 버튼을 누를때 마다 소리가 동일하지 않다 그 이유는 주파수 값 즉 카운트는 계쏙 하고있는데 중간에 start를 하면 주파수값이 바뀌기 때문에 일정한 소리를 내기위해
	/// 아래 문장을 추가한다.
	__HAL_TIM_SET_COUNTER(hBuzzTim,0);
}

void Buzzer_StopFreq() {
	// PWM stop
	HAL_TIM_PWM_Stop(hBuzzTim, buzzChannel);
}

void Buzzer_GenFreq(uint16_t frequency) {

	uint16_t arr = (100000 / frequency) - 1;
	uint16_t ccr = arr / 2;

	__HAL_TIM_SET_AUTORELOAD(hBuzzTim, arr);
	__HAL_TIM_SET_COMPARE(hBuzzTim, buzzChannel, ccr);
}
