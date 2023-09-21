/*
 * mainpp.h
 *
 *  Created on: Jul 23, 2023
 *      Author: paul3
 */

#ifndef INC_MAINPP_H_
#define INC_MAINPP_H_

#ifdef __cplusplus
 extern "C" {
#endif

 extern int flag;
 extern double Vx , Vy , W, rVx, rVy, rW;

 void main_function();



 	//STM_main
 	void stm_setup(void);
 	//timer operate automatically after setup, so STM don't need STM_loop?


#ifdef __cplusplus
}
#endif


#endif /* INC_MAINPP_H_ */
