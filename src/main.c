#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "module.h"
#include "app.h"



int main(int argc, char const *argv[])
{
	char command_in[MAX_BUFF_LEN];
	bool_t valid_cmd, usr_verify = FALSE;
	uint16_t value_rdd;

	do
	{
		command_read(command_in);
		valid_cmd = cmd_validation(command_in);

		if(!valid_cmd)
			send_info("\nError: wrong format\r\n");

	}while(!valid_cmd);

	
	if(!strncmp(command_in, "read voltage", MAX_BUFF_LEN))
	{
		value_rdd = APP_ReadVoltage();
	}
	else if(!strncmp(command_in, "read current", MAX_BUFF_LEN))
	{
		value_rdd = APP_ReadCurrent();
	}
	else
	{
		usr_verify = TRUE;
	}
	
	

	return 0;
}