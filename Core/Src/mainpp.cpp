/*
 * mainpp.cpp
 *
 *  Created on: Jul 23, 2023
 *      Author: paul3
 */
#include <ros_port.h>
#include "mainpp.h"
#include "pusher.h"
#include "chassis_DCmotor.h"
#include "stm32h7xx_hal.h"
#include "script.h"


extern SCRIPT script_a;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim23;

int a=0;
int flag = 0;
double Vx = 0, Vy = 0, W, rVx, rVy, rW;

void main_function(){
	PUSHER pusher_A;
	PUSHER pusher_B;
//	PUSHER pusher_C;
//	PUSHER pusher_D;
//	SCRIPT script_a;
	ros_setup();
	stm_setup();
	script_a.scriptrun = 0;
	while(1){
		a++;
		ros_loop();

		pusher_A.distence();
		pusher_B.distence();
		if(flag == 6 ){
			script_a.scriptrun = 1;
		}
		else if(flag == 7){

		}
		script();

	}
}
void stm_setup(void){
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim8);
	HAL_TIM_Base_Start_IT(&htim23);//main Timer
	DC_motor_init();
}
