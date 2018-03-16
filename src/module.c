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
const uint8_t MAX_BUFF_LEN   = 25;
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
		else
			data_in = 0;
	}
	cmd_in[ctr] = '\0';

	return strlen(cmd_in);
}


bool_t cmd_validation(const char *cmd)
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


uint8_t get_command_type(const char *cmd)
{
	if(!strncmp(cmd, "read voltage", MAX_BUFF_LEN))
		return READ_VOLTAGE;
	else if(!strncmp(cmd, "read current", MAX_BUFF_LEN))
		return READ_CURRENT;
	else
		return USR_VERIFY;
}


void build_rtn_str(uint16_t input_val, uint8_t cmd_type, char *out_str)
{
	float value;

	if(cmd_type != USR_VERIFY)
		value = input_val * 0.01;

	switch(cmd_type)
	{
		case READ_VOLTAGE:
			sprintf(out_str, "Voltage: %.2fV", value);
			break;
		case READ_CURRENT:
			sprintf(out_str, "Current: %.2fA", value);
			break;
		case USR_VERIFY:
			sprintf(out_str, "%s", "\nOK\r\n");
	}
}


void send_info(const char *out_str)
{
	uint8_t len, i;
	len = strlen(out_str);
	printf("Throught serial port\n");
	for(i = 0; i < len; i++)
		SER_WriteByte(out_str[i]);
}
