/*
 * btn.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "button.h"

int btn_flag [4] = {0, 0, 0, 0};

GPIO_TypeDef *BTN_PORT [4] = {BTN1_GPIO_Port, BTN2_GPIO_Port, BTN3_GPIO_Port, BTN4_GPIO_Port};
uint16_t BTN_PIN [4] = {BTN1_Pin, BTN2_Pin, BTN3_Pin, BTN4_Pin};

int KeyReg0 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3 [4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress [4] = {500, 500, 500, 500};

int isButtonPressed(int btn){
	if (btn_flag[btn] == 1){
		btn_flag[btn] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int btn){
	btn_flag[btn] = 1;
}


void getKeyInput(int btn){
	KeyReg0[btn] = KeyReg1[btn];
	KeyReg1[btn] = KeyReg2[btn];
	KeyReg2[btn] = HAL_GPIO_ReadPin(BTN_PORT[btn], BTN_PIN[btn]);
	if ((KeyReg0[btn] == KeyReg1[btn]) && (KeyReg1[btn] == KeyReg2[btn])){
		if (KeyReg3[btn] != KeyReg2[btn]){
			KeyReg3[btn] = KeyReg2[btn];
			if (KeyReg2[btn] == PRESSED_STATE){
				subKeyProcess(btn);
				TimerForKeyPress[btn] = 500;
			}
		}
		else{
			TimerForKeyPress[btn]--;
			if (TimerForKeyPress[btn] <= 0){
				KeyReg3[btn] = NORMAL_STATE;
			}
		}
	}
}
