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
extern SCRIPT script_b;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim23;

int a=0;
int flag = 0;
double Vx = 0, Vy = 0, W, rVx, rVy, rW;
int script_state = 0;
int pusher_reset_state = 0;

void main_function(){
	PUSHER pusher_A;
	PUSHER pusher_B;
//	PUSHER pusher_C;
//	PUSHER pusher_D;
//	SCRIPT script_a;
	ros_setup();
	stm_setup();
	pusher_reset();
	script_a.scriptrun = 0;
	script_b.scriptrun = 0;
	pusher_reset();
	while(1){
		a++;
		ros_loop();
		if(flag == 6 ){
			script_a.scriptrun = 1;
			flag = 0;
		}
		if(flag == 7){
			script_b.scriptrun = 1;
			flag = 0;
		}
		while(script_a.scriptrun == 1 || script_b.scriptrun == 1){
			if(everRun == 1 || everRun2 == 1){
				script_a.scriptrun = 0;
				script_b.scriptrun = 0;
			}
			script();
		}

	}
}
void stm_setup(void){
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim8);
	HAL_TIM_Base_Start_IT(&htim23);//main Timer
	DC_motor_init();
}

int detectFallingEdge(int current){
	static int prev = 0;
	int temp;
	temp = !current && prev;
	prev = current;
	return temp;
}
