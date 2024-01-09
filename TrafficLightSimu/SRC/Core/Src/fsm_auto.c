/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_auto.h"

int initMode[2] = {RED, GREEN};


int initDuration(int lane){
	return (lane == 1)? GREEN_DURATION : RED_DURATION;
}

void fsm_auto_run(int lane){
	switch(LED_MODE[lane]){
		case INIT:
			setTrafficLight(lane, OFF);

			LED_MODE[lane] = initMode[lane];
			setTimer(lane, initDuration(lane)*100);

			break;
		case RED:
			setTrafficLight(lane, RED);

			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
				LED_MODE[lane] = GREEN;
				setTimer(lane, GREEN_DURATION*100);
			}

			break;
		case GREEN:
			setTrafficLight(lane, GREEN);

			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
				LED_MODE[lane] = AMBER;
				setTimer(lane, AMBER_DURATION*100);
			}

			break;
		case AMBER:
			setTrafficLight(lane, AMBER);

			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
				LED_MODE[lane] = RED;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		default:
			break;
	}
}
