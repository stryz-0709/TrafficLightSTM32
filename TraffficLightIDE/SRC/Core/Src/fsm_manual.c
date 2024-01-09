/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;

int LIGHT[8] = {RED, RED, GREEN, AMBER, GREEN, AMBER, RED, RED};
int manualMode[2] = {0, 4};

void manualPlus(int lane){
	manualMode[lane] += 1;
	if (manualMode[lane] > (lane+1)*4-1) manualMode[lane] = lane*4;
	LED_MODE[lane] = LIGHT[manualMode[lane]];
}

void manualMinus(int lane){
	manualMode[lane] -= 1;
	if (manualMode[lane] < lane*4) manualMode[lane] = (lane+1)*4-1;
	LED_MODE[lane] = LIGHT[manualMode[lane]];
}

//Change mode
void changeMode(int mode, int duration, int ledMode){
	//Display duration
	tempDuration = duration;

	//Change traffic lights to toggle the right color
	LED_MODE[0] = ledMode;
	LED_MODE[1] = ledMode;

	//Change ped light mode
	LED_MODE[2] = ledMode;

	//Turn off all lights
	setTrafficLight(0, OFF);
	setTrafficLight(1, OFF);

	//Update mode
	TRAFFIC_MODE = mode;

	//Set timer to toggle lights
	setTimer(3, 25);
}


//Increment duration
void increaseDuration(int mode){
	tempDuration++;
	if (tempDuration == 10) tempDuration = 1;

	//Display duration
	display7SEG(tempDuration);
}

void decreaseDuration(int mode){
	tempDuration--;
	if (tempDuration == 0) tempDuration = 9;

	//Display duration
	display7SEG(tempDuration);
}


//Toggle Lights
void toggle(int mode){
	toggleLight(0, mode);
	toggleLight(1, mode);
	setTimer(3, 25);
}


void displayCountdown(){
	if (timer_counter[0] % 100 == 0){
		display7SEG(timer_counter[0] /100);
//		setTimer(5,100);
	}
}


//Check and update duration so that RED = GREEN + AMBER
void checkDuration(int mode){
	int lane = GREEN_DURATION + AMBER_DURATION;
	switch (mode){
	case RED:
		if (lane != RED) GREEN_DURATION = RED_DURATION - AMBER_DURATION;
		break;
	case AMBER:
		if (lane != RED) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	case GREEN:
		if (lane != RED) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	}
}

void fsm_manual_run(){
	switch(TRAFFIC_MODE){
		case AUTO:
			displayCountdown();
			if (isButtonPressed(0)){
				changeMode(MANUAL, 0, INIT);
				display7SEG(USER);
			}
			break;

		case MANUAL:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(RED, RED_DURATION, OFF);
				display7SEG(RED_DURATION);
			}

			if (isButtonPressed(2)){
				manualPlus(0);
				manualPlus(1);
			}
			if (isButtonPressed(3)){
				manualMinus(0);
				manualMinus(1);
			}
			break;

		case RED:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(AMBER, AMBER_DURATION, OFF);
				display7SEG(AMBER_DURATION);
			}

			//Change duration
			if (isButtonPressed(3)) increaseDuration(RED);

			if (isButtonPressed(2)) decreaseDuration(RED);

			//Save duration
			if (isButtonPressed(1)){
				RED_DURATION = tempDuration;
				checkDuration(RED);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(RED);
			break;

		case AMBER:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(GREEN, GREEN_DURATION, OFF);
				display7SEG(GREEN_DURATION);
			}

			//Change duration
			if (isButtonPressed(3))	increaseDuration(AMBER);

			if (isButtonPressed(2))	decreaseDuration(AMBER);

			//Save duration
			if (isButtonPressed(1)){
				AMBER_DURATION = tempDuration;
				checkDuration(AMBER);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(AMBER);
			break;

		case GREEN:
			//Change mode
			if (isButtonPressed(0)) changeMode(AUTO, 0, INIT);

			//Change duration
			if (isButtonPressed(3)) increaseDuration(GREEN);

			if (isButtonPressed(2)) decreaseDuration(GREEN);


			//Save duration
			if (isButtonPressed(1)){
				GREEN_DURATION = tempDuration;
				checkDuration(GREEN);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(GREEN);
			break;

		default:
			 break;
	}
}
