/*
 * script.cpp
 *
 *  Created on: 2023年8月16日
 *      Author: paul3
 */
#include "script.h"
#include "pusher.h"
#include "servo.h"
#include "mainpp.h"

SCRIPT script_a;
SCRIPT script_b;
//extern PUSHER pusher_A;
//extern PUSHER pusher_B;
//extern PUSHER pusher_C;
//extern PUSHER pusher_D;
int everRun = 0;
int everRun2 = 0;

//void pusher_reset(){
//	script_pusher(-15,-15);
//}
void script(){
	if(script_a.scriptrun == 1){
		if(delay_start == 0){
			script_wheel(5,0,0);
			script_pusher(5,5);
			delay_start = 1;
		}
		if(delay == 250 && delay_start == 1){
			script_wheel(0,0,0);
			script_pusher(13,5);
			delay_start = 2;
		}
		if(delay == 550 && delay_start == 2){
			script_wheel(20,0,0);
			delay_start = 3;
		}
		if(delay == 850 && delay_start == 3){
			script_wheel(0,0,0);
			script_pusher(-2,13);
			delay_start = 4;
		}
		if(delay == 1100 && delay_start == 4){
			script_wheel(0,0,0);
			script_wheel(20,0,0);
			script_pusher(-2,13);
			delay_start = 5;
		}
		if(delay == 1200 && delay_start == 5){/*-50*/
//			script_pusher(-2,10);
			script_wheel(15,0,0);
			delay_start = 6;
		}
		if(delay == 1400 && delay_start == 6){/*-50*/
			script_wheel(0,0,0);
			script_wheel(30,0,0);
			delay_start = 6;
		}
		if(delay == 1400 && delay_start == 6){/*-50*/
			script_wheel(10,0,0);
			script_pusher(13,-2);
			delay_start = 7;
		}
		if(delay == 1700 && delay_start == 7){
			script_wheel(15,0,0);
//			script_pusher(12,0);
			delay_start = 8;
		}
		if(delay == 2000 && delay_start == 8){
			script_wheel(0,0,0);
			script_pusher(-2,11);
			delay_start = 9;
		}
//		if(delay == 2000 && delay_start == 8){
//			script_wheel(0,0,0);
//			script_pusher(-2,10);
//			delay_start = 9;
//		}
		if(delay == 2500 && delay_start == 9){
			script_wheel(15,0,0);
			delay_start = 10;
		}
		if(delay == 2900 && delay_start == 10){
			script_wheel(0,0,0);
			script_pusher(-2,15);
			delay_start = 0;
			script_a.scriptrun = 0;
			delay = 0;
			everRun =1;
		}
	}
	if(script_b.scriptrun == 1){
		if(delay_start_2 == 0){
			script_pusher(3,12);
			script_wheel(10,0,0);
			UART_Send_SetMotorPosition(3, 1650, 500);
			UART_Send_SetMotorPosition(1, 850, 500);
			delay_start_2 =1;
		}
		if(delay_2 == 550 && delay_start_2 == 1){
			script_pusher(-2,12);
			UART_Send_SetMotorPosition(1, 1300, 1500);
			UART_Send_SetMotorPosition(3, 1200, 1500);
			script_wheel(0,0,0);
			delay_start_2 =2;
		}
		if(delay_2 == 750 && delay_start_2 == 2){
			script_pusher(-2,12);
			UART_Send_SetMotorPosition(1, 1300, 1500);
			UART_Send_SetMotorPosition(3, 1200, 1500);
			script_wheel(2,0,0);
			delay_start_2 =3;
		}
		if(delay_2 == 1500 && delay_start_2 == 3){
//			UART_Send_SetMotorPosition(1, 1300, 300);
			script_wheel(10,0,0);
//			script_pusher(-2,12);
			delay_start_2 =4;
		}
		if(delay_2 == 2100 && delay_start_2 == 4){
			UART_Send_SetMotorPosition(1, 1400, 500);
			UART_Send_SetMotorPosition(3, 1100, 500);
			script_wheel(0,0,0);
			delay_start_2 =0;
			script_b.scriptrun =0;
			delay_2 = 0;
			everRun2 = 1;
		}
	}

}
void script_wheel(double s_Vx,double s_Vy,double s_w){
	Vx = s_Vx;
	Vy = s_Vy;
	W = s_w;
}
//void script_pusher(double hight_a,double hight_b,double hight_c,double hight_d){
//	pusher_A.state = hight_a;
//	pusher_B.state = hight_b;
//	pusher_C.state = hight_c;
//	pusher_D.state = hight_d;
//}

