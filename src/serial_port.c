#include <stdint.h>
#include <stdio.h>
#include "serial_port.h"

const char test_str[] = "read vol\b\b\bcurrent\r";
const char true_str[] = "read current";


bool_t SER_ReadByte(uint8_t *pu8ReadByte)
{
	static uint8_t i = -1;
	i++;
	*pu8ReadByte = test_str[i];
	return true;
}

void SER_WriteByte(uint8_t u8Byte)
{
	printf("%c\n", u8Byte);
}
