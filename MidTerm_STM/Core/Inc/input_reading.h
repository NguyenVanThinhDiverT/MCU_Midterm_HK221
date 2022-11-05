/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 					3
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET
#define DURATION_FOR_AUTO_INCREASING 	300

void getKeyInput(void);
unsigned char is_button_pressed (uint8_t index );
unsigned char is_button_pressed_3s (uint8_t index);
int which_button_press(void);
int which_button_press3s(void);
int press_or_press3s(void);
int which_button_press3s(void);
int press_or_press3s(void);
int press_release(void);

#endif /* INC_INPUT_READING_H_ */
