/*
 * FSM_DEC.c
 *
 *  Created on: Nov 6, 2022
 *      Author: WELCOME
 */

#include <FSM_LED.h>


#define INIT 	0
#define ON 		1
#define OFF 	2

int status = 0;
void fsm_dec(void){
	switch(status){
		case INIT:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			status = ON;
			setTimer1(100);
			break;
		case ON:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			if(timer1_flag == 1){
				status=OFF;
				setTimer1(100);
			}
			break;
		case OFF:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			if(timer1_flag == 1){
				status = ON;
				setTimer1(100);
			}
			break;
		default:
			break;
	}
}


