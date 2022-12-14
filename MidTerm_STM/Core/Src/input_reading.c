/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */

#include "input_reading.h"



static GPIO_PinState KeyReg0 			[N0_OF_BUTTONS];
static GPIO_PinState KeyReg1			[N0_OF_BUTTONS];
static GPIO_PinState KeyReg2 			[N0_OF_BUTTONS];
static GPIO_PinState KeyReg3 			[N0_OF_BUTTONS];

static uint8_t buttonBuffer 			[N0_OF_BUTTONS];
static uint8_t flagForButtonPress3s 	[N0_OF_BUTTONS];
static uint16_t counterForButtonPress3s [N0_OF_BUTTONS];

int FLAG_CHECK_PRESSED[N0_OF_BUTTONS] =	{1,1,1};

void getKeyInput (void) {
	for (int i = 0; i < N0_OF_BUTTONS ; i++) {
			KeyReg0[i] = KeyReg1[i];
			KeyReg1[i] = KeyReg2[i];

			if (i==0){
				KeyReg2[i] = HAL_GPIO_ReadPin(BUT_RESET_GPIO_Port, BUT_RESET_Pin);
			}
			if (i==1){
				KeyReg2[i] = HAL_GPIO_ReadPin(BUT_INC_GPIO_Port, BUT_INC_Pin);
			}
			if (i==2){
				KeyReg2[i] = HAL_GPIO_ReadPin(BUT_DEC_GPIO_Port, BUT_DEC_Pin);
			}

			if(KeyReg0[i] == KeyReg1[i] && KeyReg1[i] == KeyReg2[i]){
				if(KeyReg3[i] != KeyReg2[i]){
					KeyReg3[i] = KeyReg2[i];
					if(KeyReg3[i] == BUTTON_IS_PRESSED){
						buttonBuffer[i] = BUTTON_IS_PRESSED;
						counterForButtonPress3s[i] = DURATION_FOR_AUTO_INCREASING;
					}else{
						buttonBuffer[i] = BUTTON_IS_RELEASED;
						flagForButtonPress3s[i] = 0;
						FLAG_CHECK_PRESSED[i] = 1;
					}
				}else{
					if(KeyReg3[i] == BUTTON_IS_PRESSED){
						counterForButtonPress3s[i]--;
						if(counterForButtonPress3s[i] == 0){
							flagForButtonPress3s[i] = 1;
						}
					}
			}
		}
	}
}
unsigned char is_button_pressed (uint8_t index) {
	if(index >= N0_OF_BUTTONS ) return 0;
	if(buttonBuffer[index] == BUTTON_IS_PRESSED && FLAG_CHECK_PRESSED[index] == 1 ){
		FLAG_CHECK_PRESSED[index] = 0;
		return 1;
	}
	return 0;
}
unsigned char is_button_pressed_3s (uint8_t index) {
	if(index >= N0_OF_BUTTONS) return 0;
	return (flagForButtonPress3s[index]==1);
}

int which_button_press(void){
	for(int i=0; i< N0_OF_BUTTONS; i++){
		if(is_button_pressed(i)){
			return (i);
		}
	}
	return N0_OF_BUTTONS;
}
int which_button_press3s(void){
	for(int i=1; i<N0_OF_BUTTONS; i++){
		if(is_button_pressed_3s(i)){
			return (i);
		}
	}
	return N0_OF_BUTTONS;
}
int press_or_press3s(void){
	for(int i=0 ; i<N0_OF_BUTTONS; i++){
		if((buttonBuffer[i] == BUTTON_IS_PRESSED && FLAG_CHECK_PRESSED[i]==1)){
			return 0; // pressed
		}
	}
	for(int i=0;i<N0_OF_BUTTONS;i++){
		if(flagForButtonPress3s[i]==1){
			return 1; // pressed1s
		}
	}
	return -1;
}
int press_release(void){
	for(int i=0; i < N0_OF_BUTTONS; i++){
		if(buttonBuffer[i] != BUTTON_IS_RELEASED ){
			return 1;
		}
	}
	return -1;
}
