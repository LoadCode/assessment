#include <stdio.h>
#include <stdint.h>
#include "unit_test.h"
#include "module.h"
#include "serial_port.h"
#include "app.h"


const uint8_t BCK_SPACE_CHAR = 8;
const uint8_t NEW_LINE_CHAR  = 10;
const uint8_t CARRIAGE_RTRN  = 13;


uint8_t command_read(char *cmd_in)
{
	char data_in = 0;
	uint8_t ctr  = 0;

	while(data_in != CARRIAGE_RTRN)
	{
		if(read_serial(&data_in))
		{
			
		}
	}

	return 0;
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
