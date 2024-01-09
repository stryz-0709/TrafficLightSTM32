/*
 * global.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "fsm_auto.h"
#include "fsm_manual.h"

//First state of fsm_automatic
#define INIT 1

#define AUTO 11 //To make fsm_automatic run
#define OFF 12 //To make fsm_automatic stop working
#define MANUAL 13  //To add pedestrian light
#define USER 14

//Three modes for light, reusable
#define RED 21
#define AMBER 22
#define GREEN 23

#define SAVED 31
#define TUNING 32
#define COUNTDOWN 33
#define DEBUGGER 34

extern int LED_MODE [2];

extern int TRAFFIC_MODE; //AUTO_MODE, MANUAL_MODE, EDIT_MODE

//Light duration
extern int RED_DURATION;
extern int AMBER_DURATION;
extern int GREEN_DURATION;

extern int counter1;
extern int counter2;

#endif /* INC_GLOBAL_H_ */
