#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "unit_test.h"
#include "module.h"
#include "serial_port.h"
#include "app.h"


const uint8_t BCK_SPACE_CHAR = 8;
const uint8_t NEW_LINE_CHAR  = 10;
const uint8_t CARRIAGE_RTRN  = 13;
const uint8_t MAX_BUFF_LEN   = 20;
const uint8_t MIN_BUFF_IDX   = 0;



uint8_t command_read(char *cmd_in)
{
	char data_in = 0;
	uint8_t ctr  = 0;

	while(data_in != CARRIAGE_RTRN)
	{
		if(read_serial(&data_in))
		{
			if(data_in == BCK_SPACE_CHAR)
			{
				ctr--;
			}
			else if(data_in == CARRIAGE_RTRN)
			{
				break;
			}
			else
			{
				cmd_in[ctr] = data_in;
				ctr++;
			}

			// Prevent buffer overflow attack
			if(ctr >= MAX_BUFF_LEN || ctr <= MIN_BUFF_IDX)
				break;
		}
	}
	cmd_in[ctr] = '\0';

	return strlen(cmd_in);
}


bool_t cmd_validation(char *cmd)
{
	return true;
}


void build_rtn_str(uint16_t value, const char *cmd, char *out_str)
{

}


void send_info(const char *out_str)
{

}
