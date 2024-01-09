/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "traffic_light.h"

uint16_t REDLIGHT [2] = {RED1_Pin, RED2_Pin};
uint16_t GREENLIGHT [2] = {GREEN1_Pin, GREEN2_Pin};
uint16_t AMBERLIGHT [2] = {AMBER1_Pin, AMBER2_Pin};
GPIO_TypeDef * GPIO_Port [6] = {GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA};

void setTrafficLight(int lane, int light){
	switch(light){
	case RED:
		HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], RESET);
		HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
		break;
	case AMBER:
		HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], RESET);
		HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
		break;
	case OFF:
		HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
		HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
		break;
	default:
		break;
	}

}

void toggleLight(int lane, int light){
	switch (light){
		case RED:
			HAL_GPIO_TogglePin(GPIOA, REDLIGHT[lane]);
			HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
			HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
			break;
		case AMBER:
			HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
			HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
			HAL_GPIO_TogglePin(GPIOA, AMBERLIGHT[lane]);
			break;
		case GREEN:
			HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
			HAL_GPIO_TogglePin(GPIOA, GREENLIGHT[lane]);
			HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
			break;
		default:
			break;
	}
}



void display7SEG(int num){
  switch(num){
	case 0:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 1:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 2:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 3:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 4:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 5:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 6:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 7:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 8:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 9:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case OFF:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case USER:
	  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	default:
	  break;
  }
}
