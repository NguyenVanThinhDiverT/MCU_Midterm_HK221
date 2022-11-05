/*
 * fsm_buttons_run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */


#include "fsm_buttons_run.h"
#include "input_reading.h"


int counter = 0;
int counter10S = 0;
int first_time_release = 0;
int flag3s = 1;

int status_button = INIT;

void fsm_buttons_run(void){
	switch(status_button){
		case INIT:
			status_button = RELEASE;
			break;

		case PRESSED:
			counter10S = 0;
			first_time_release = 1;

			if(press_or_press3s() == PRESSED_3S){
				status_button = PRESSED_3S;

			}else if(press_release() == RELEASE){
				status_button = RELEASE;

			}else {
				//select button mode
							switch(which_button_press()){
								case RESET:
									counter=0;
									break;
								case INC:
									counter++;
									break;
								case DEC:
									counter--;
									break;
								default:
									break;
							}
							if(counter > 9) {
								counter = 0;
							}
							if(counter < 0) {
								counter = 9;
							}
							display7SEG(counter);
			}

			break;
		case PRESSED_3S:
			counter10S = 0;
			first_time_release = 1;
			if(press_release() == RELEASE){
				status_button = RELEASE;
			}else{
				switch(which_button_press3s()){
					case INC:
						if(flag3s == 1){
							counter++;
							setTimer2(100);
							flag3s = 0;
						}
						if(timer2_flag==1){
							counter++;
							setTimer2(100);
						}
						break;
					case DEC:
						if(flag3s==1){
							counter--;
							setTimer2(100);
							flag3s = 0;
						}
						if(timer2_flag == 1){
							counter--;
							setTimer2(100);
						}
						break;
					default:
						break;
				}
				if(counter > 9) {
					counter = 0;
				}
				if(counter < 0) {
					counter = 9;
				}
				display7SEG(counter);
			}
			break;
		case RELEASE:
			if(press_or_press3s() == PRESSED){
				status_button = PRESSED;
			}else{ // update with funtion fsm_upgrades_buttons_run
							if(first_time_release == 1){
								first_time_release = 0;
								setTimer2(100);
							}
							if(timer2_flag==1){
								counter10S++;
								if(counter10S >= 10){
									if(counter>0) {
										counter--;
									}
								}
								setTimer2(100);
							}
							display7SEG(counter);
			}
			break;
		default:
			break;
	}
}
void fsm_simple_buttons_run(void){
	switch(which_button_press()){
		case RESET:
			counter=0;
			break;
		case INC:
			counter++;
			break;
		case DEC:
			counter--;
			break;
		default:
			break;
	}
	if(counter > 9) {
		counter = 0;
	}
	if(counter < 0) {
		counter = 9;
	}
	display7SEG(counter);
}
void fsm_upgrade_buttons_run(void){
	switch(status_button){
		case INIT:
			status_button = RELEASE;
			break;

		case PRESSED:
			counter10S = 0;
			first_time_release = 1;

			if(press_or_press3s() == PRESSED_3S){
				status_button = PRESSED_3S;

			}else if(press_release() == RELEASE){
				status_button = RELEASE;

			}else {
				//select button mode
							switch(which_button_press()){
								case RESET:
									counter=0;
									break;
								case INC:
									counter++;
									break;
								case DEC:
									counter--;
									break;
								default:
									break;
							}
							if(counter > 9) {
								counter = 0;
							}
							if(counter < 0) {
								counter = 9;
							}
							display7SEG(counter);
			}

			break;
		case PRESSED_3S:
			counter10S = 0;
			first_time_release = 1;
			if(press_release() == RELEASE){
				status_button = RELEASE;
			}else{
				switch(which_button_press3s()){
					case INC:
						if(flag3s == 1){
							counter++;
							setTimer2(100);
							flag3s = 0;
						}
						if(timer2_flag==1){
							counter++;
							setTimer2(100);
						}
						break;
					case DEC:
						if(flag3s==1){
							counter--;
							setTimer2(100);
							flag3s = 0;
						}
						if(timer2_flag == 1){
							counter--;
							setTimer2(100);
						}
						break;
					default:
						break;
				}
				if(counter > 9) {
					counter = 0;
				}
				if(counter < 0) {
					counter = 9;
				}
				display7SEG(counter);
			}
			break;
		case RELEASE:
			if(press_or_press3s() == PRESSED){
				status_button = PRESSED;
			}
//			else{
//							if(first_time_release == 1){
//								first_time_release = 0;
//								setTimer2(100);
//							}
//							if(timer2_flag==1){
//								counter10S++;
//								if(counter10S >= 10){
//									if(counter>0) {
//										counter--;
//									}
//								}
//								setTimer2(100);
//							}
//							display7SEG(counter);
//			}
			break;
		default:
			break;
	}
}
