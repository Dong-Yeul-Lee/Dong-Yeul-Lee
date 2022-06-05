/*
 * UltraSonic.h
 *
 *  Created on: Jan 7, 2022
 *      Author: 82102
 */

#ifndef DRIVER_ULTRASONIC_H_
#define DRIVER_ULTRASONIC_H_

#include "main.h"

#define CLEAR			0
#define READY			1


void UltraSonic_SetCounter(uint16_t counter);
uint16_t UltraSonic_GetCounter();
void UltraSonic_SetReadyFlag(uint8_t flag) ;
void UltraSonicTrigger() ;
uint8_t UltraSonic_Is_Ready() ;
uint16_t UltraSonic_GetDistance() ;
void UltraSonic_ISR_Process() ;





#endif /* DRIVER_ULTRASONIC_H_ */
