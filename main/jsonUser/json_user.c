/*
 * json_user.c
 *
 *  Created on: Jun 14, 2022
 *      Author: ASUS
 */

#include "json_user.h"
#include "../common.h"

void JSON_analyze_post(char* my_json_string, char * deviceid, char * devicetoken)
{
	cJSON *root = cJSON_Parse(my_json_string);
	cJSON *current_element = NULL;
	cJSON_ArrayForEach(current_element, root)
	{
		if (current_element->string)
		{
			const char* string = current_element->string;
			if(strcmp(string, "deviceid") == 0)
			{
				memcpy(deviceid, current_element->valuestring, strlen(current_element->valuestring));
			}
			if(strcmp(string, "devicetoken") == 0)
			{
				memcpy(devicetoken, current_element->valuestring, strlen(current_element->valuestring));
			}
		}
	}
	cJSON_Delete(root);
}

void JSON_analyze_SUB(char* my_json_string, cmd * sub_cmd)
{
	cJSON *root = cJSON_Parse(my_json_string);
	cJSON *current_element = NULL;
	cJSON_ArrayForEach(current_element, root)
	{
		if (current_element->string)
		{
			const char* string = current_element->string;
			if(strcmp(string, "action") == 0)
			{
				memcpy(sub_cmd->action, current_element->valuestring, strlen(current_element->valuestring));
			}
			if(strcmp(string, "nodeId") == 0)
			{
				memcpy(sub_cmd->nodeID, current_element->valuestring, strlen(current_element->valuestring));
			}
			if(strcmp(string, "eui64") == 0)
			{
				memcpy(sub_cmd->EUI64, current_element->valuestring, strlen(current_element->valuestring));
			}
			if(strcmp(string, "endpoint") == 0)
			{
				sub_cmd->endpoint = current_element->valueint;
			}
			if(strcmp(string, "value") == 0)
			{
				memcpy(sub_cmd->value, current_element->valuestring, strlen(current_element->valuestring));
			}
			if(strcmp(string,"url") == 0)
			{
				memcpy(sub_cmd->url, current_element->valuestring, strlen(current_element->valuestring));
			}
		}
	}
	cJSON_Delete(root);
}
