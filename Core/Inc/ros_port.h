/*
 * ROS_port.h
 *
 *  Created on: Sep 20, 2023
 *      Author: kch93
 */

#ifndef INC_ROS_PORT_H_
#define INC_ROS_PORT_H_

#include "ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"

void vel_callback(const geometry_msgs::Twist &msg);
void ori_callback(const std_msgs::Int8 &msg);
void pub(void);

void ros_setup(void);
void ros_loop(void);



#endif /* INC_ROS_PORT_H_ */
