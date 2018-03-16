#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "module.h"
#include "serial_port.h"
#include "app.h"

// ASCII Characters for:
const uint8_t BCK_SPACE_CHAR = 8;
const uint8_t NEW_LINE_CHAR  = 10;
const uint8_t CARRIAGE_RTRN  = 13;
const uint8_t MAX_BUFF_LEN   = 20;
const uint8_t MIN_BUFF_IDX   = 0;



uint8_t command_read(char *cmd_in)
{
	uint8_t data_in = 0;
	uint8_t ctr  = MIN_BUFF_IDX;

	while(data_in != CARRIAGE_RTRN)
	{
		if(SER_ReadByte(&data_in))
		{
			if(data_in == BCK_SPACE_CHAR)
			{
				ctr--;
			}
			else if(data_in == CARRIAGE_RTRN)
			{
				if(ctr == MIN_BUFF_IDX)
				{
					cmd_in[ctr] = 'v'; // Verify action from user
					ctr++;
				}					
				break;
			}
			else if(data_in == NEW_LINE_CHAR)
			{
				continue;
			}	
			else
			{
				cmd_in[ctr] = data_in;
				SER_WriteByte(data_in); // echo
				ctr++;
			}

			// Simple prevention for buffer overflow attack
			if(ctr >= MAX_BUFF_LEN)
				break;
			else if(ctr < MIN_BUFF_IDX)
				ctr = MIN_BUFF_IDX;
		}
	}
	cmd_in[ctr] = '\0';

	return strlen(cmd_in);
}


bool_t cmd_validation(char *cmd)
{
	// Valid commands
	char read_current_cmd[] = "read current";
	char read_voltage_cmd[] = "read voltage";
	char usr_verify_cmd[]   = "v";

	if(!strncmp(read_current_cmd, cmd, MAX_BUFF_LEN) || \
	   !strncmp(read_voltage_cmd, cmd, MAX_BUFF_LEN) || \
	   !strncmp(usr_verify_cmd, cmd, MAX_BUFF_LEN)
	  )
		return TRUE;
	else
		return FALSE;

}


void build_rtn_str(uint16_t value, const char *cmd, char *out_str)
{

}


void send_info(char *out_str)
{
	uint8_t len, i;
	len = strlen(out_str);
	printf("len = %d\n", len);

	for(i = 0; i < len; i++)
		SER_WriteByte(out_str[i]);
}
