/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "traffic_light.h"

uint16_t REDLIGHT [2] = {RED1_Pin, RED2_Pin};
uint16_t GREENLIGHT [2] = {GREEN1_Pin, GREEN2_Pin};
uint16_t AMBERLIGHT [2] = {YELLOW1_Pin, YELLOW2_Pin};
GPIO_TypeDef *GPIO [4] = {GPIOA, GPIOA, GPIOB, GPIOC};

void setTrafficLightDefault(int lane){
	HAL_GPIO_WritePin(GPIO[lane*2], REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], AMBERLIGHT[lane], SET);
}

void setTrafficLightRed(int lane){
	HAL_GPIO_WritePin(GPIO[lane*2], REDLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], AMBERLIGHT[lane], SET);
}

void setTrafficLightGreen(int lane){
	HAL_GPIO_WritePin(GPIO[lane*2], REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], GREENLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], AMBERLIGHT[lane], SET);
}
void setTrafficLightAmber(int lane){
	HAL_GPIO_WritePin(GPIO[lane*2], REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIO[lane*2+1], AMBERLIGHT[lane], RESET);
}

void display7SEG(int num){
  switch(num){
	case 0:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 1:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 2:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 3:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 4:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, SET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 5:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 6:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 7:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
	  break;
	case 8:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	case 9:
	  HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOC, SEG1_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
	  HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
	  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
	  break;
	default:
	  break;
  }
}
