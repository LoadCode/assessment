#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "serial_port.h"

//const char test_str[] = "ra\bead val\b\boltageh\b\n\r";
const char test_str[] = "ra\bead val\b\b\bcurrent\n\r";

bool_t SER_ReadByte(uint8_t *pu8ReadByte)
{
	static uint8_t i = -1;
	uint8_t len;
	len = strlen(test_str);
	if(i == len)
		i = -1;
	i++;
	*pu8ReadByte = test_str[i];
	return TRUE;
}

void SER_WriteByte(uint8_t u8Byte)
{
	printf("%c\n", u8Byte);
}
