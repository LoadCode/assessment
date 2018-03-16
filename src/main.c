#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "module.h"



int main(int argc, char const *argv[])
{
	char command_in[MAX_BUFF_LEN];
	bool_t valid_cmd;

	do
	{
		command_read(command_in);
		valid_cmd = cmd_validation(command_in);

		if(!valid_cmd)
			send_info("\nError: wrong format\r\n");

	}while(!valid_cmd);

	
	
	return 0;
}