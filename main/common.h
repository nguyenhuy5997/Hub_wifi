/*
 * Common.h
 *
 *  Created on: Jun 15, 2022
 *      Author: ASUS
 */

#ifndef MAIN_COMMON_H_
#define MAIN_COMMON_H_


#include "../main/SPIFFS/spiffs_user.h"

typedef struct _dvinfor
{
	char id[50];
	char token[50];
}Device;

typedef struct _cmd
{
	char action[50];
	char nodeID[6];
	char EUI64[18];
	uint8_t endpoint;
	char value[20];
	char url[100];
}cmd;
void get_device_infor(Device * _device);





#endif /* MAIN_COMMON_H_ */
