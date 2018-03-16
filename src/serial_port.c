#include <stdint.h>
#include <stdio.h>
#include "serial_port.h"

const char test_str[] = "ra\bead val\b\boltageh\n\r";
const char true_str[] = "read current";


bool_t SER_ReadByte(uint8_t *pu8ReadByte)
{
	static uint8_t i = -1;
	i++;
	*pu8ReadByte = test_str[i];
	return TRUE;
}

void SER_WriteByte(uint8_t u8Byte)
{
	printf("%c", u8Byte);
}
