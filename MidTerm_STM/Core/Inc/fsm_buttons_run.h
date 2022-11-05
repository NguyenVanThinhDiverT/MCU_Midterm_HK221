/*
 * fsm_buttons_run.h
 *
 *  Created on: Nov 5, 2022
 *      Author: WELCOME
 */

#ifndef INC_FSM_BUTTONS_RUN_H_
#define INC_FSM_BUTTONS_RUN_H_

#include "SOFTWARE_TIMER.h"
#include "LED7SEG.h"
#include "input_reading.h"

#define RESET 			0
#define INC 			1
#define DEC 			2

#define PRESSED 		0
#define PRESSED_3S 		1
#define RELEASE 		-1
#define INIT 			-2
void fsm_buttons_run(void);
void fsm_simple_buttons_run(void);
void fsm_upgrade_buttons_run(void);
extern int status_button;
#endif /* INC_FSM_BUTTONS_RUN_H_ */
