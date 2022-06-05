/*
 * buzzer.h
 *
 *  Created on: Dec 31, 2021
 *      Author: 82102
 */

#ifndef DRIVER_BUZZER_H_
#define DRIVER_BUZZER_H_

#include "main.h"

void BuzzerInit(TIM_HandleTypeDef *hBuzzTim, uint32_t buzzChannel);


void BuzzerModeButtonSound() ;
void BuzzerSpeedButtonSound() ;
void BuzzerSpeedButtonSound() ;
void Buzzer_StartFreq() ;
void Buzzer_StopFreq() ;
void Buzzer_GenFreq(uint16_t frequency) ;

void BuzzerEmergencySound();
void BuzzerTurnSignSound() ;





#endif /* DRIVER_BUZZER_H_ */
