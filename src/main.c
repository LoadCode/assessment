#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "module.h"
#include "app.h"



int main(int argc, char const *argv[])
{

	char command_in[MAX_BUFF_LEN];
	char return_str[MAX_BUFF_LEN];
	uint8_t cmd_type;
	bool_t valid_cmd;
	uint16_t value_rdd;

	/*Command input an validation*/
	do
	{
		command_read(command_in);
		valid_cmd = cmd_validation(command_in);

		if(!valid_cmd)
			send_info("\nError: wrong format\r\n");

	}while(!valid_cmd);

	cmd_type = get_command_type(command_in);

	/*carrying out the action*/	
	switch(cmd_type)
	{
		case READ_VOLTAGE:
			value_rdd = APP_ReadVoltage();
			break;
		case READ_CURRENT:
			value_rdd = APP_ReadCurrent();
			break;
	}

	/*Build return string to be send*/
	build_rtn_str(value_rdd, cmd_type, return_str);
	
	/*Lets see the return string*/
	printf("%s\n", return_str);

	/*Send info*/
	send_info(return_str);

	return 0;
}