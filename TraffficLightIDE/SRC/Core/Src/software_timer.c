/*
 * software_timer.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "software_timer.h"

int timer_counter[6] = {0, 0, 0, 0, 0, 0};
int timer_flag[6] = {0, 0, 0, 0, 0, 0};

void setTimer(int type, int duration){
	timer_counter[type] = duration;
	timer_flag[type] = 0;
}

void timerRun(int type){
	if(timer_counter[type] > 0){
		timer_counter[type]--;
		if(timer_counter[type] <= 0){
			timer_flag[type] = 1;
		}
	}
}
