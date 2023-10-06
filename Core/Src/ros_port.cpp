/*
 * ROS_port.cpp
 *
 *  Created on: Sep 20, 2023
 *      Author: kch93
 */
#include "ros_port.h"
#include "stm32h7xx_hal.h"
#include "STM32Hardware.h"
#include "ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"
#include "script.h"

#include "mainpp.h"


geometry_msgs::Twist speed;

void vel_callback(const geometry_msgs::Twist &msg)
{
	Vx = msg.linear.x;
	Vy = msg.linear.y;
	W = msg.angular.z;
}
void ori_callback(const std_msgs::Int8 &msg){
	flag = msg.data;
}

ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub_vel("/cmd_vel", vel_callback);
ros::Publisher pub_vel("/realspeed", &speed);
ros::Subscriber<std_msgs::Int8> sub_ori("/cmd_ori", ori_callback);
//ros::Subscriber<std_msgs::Int8> sub_laji("cmd_laji", laji_callback);
//ros::Publisher pub_laji("laji_ok", &speed);
void pub(void){
	speed.linear.x = rVx;
	speed.linear.y = rVy;
	speed.angular.z = rW;
<<<<<<< HEAD
	if(everRun2 == 1){//already completed flipping board
		speed.linear.z = 2;
	}
	else if(everRun == 1){//already completed crossing obstacle
		speed.linear.z = 1;
	}
	else{
		speed.linear.z = 0;
	}
=======
>>>>>>> e60cc869212c254cf3d56520931e6e217a2ebc29
	pub_vel.publish(&speed);
}
void ros_setup(void)
{
    nh.initNode();
    nh.subscribe(sub_vel);
    nh.advertise(pub_vel);
    nh.subscribe(sub_ori);
//  nh.subscribe(sub_laji);
//	nh.advertise(pub_laji);

}
void ros_loop(void)
{
    nh.spinOnce();
}
/* UART Communication */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 57600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(huart == &huart1){
    // set velocity 0 before uart reinitialization


		HAL_UART_DeInit(&huart1);
		MX_USART1_UART_Init();
		nh.getHardware()->init();
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    nh.getHardware()->flush();
}




