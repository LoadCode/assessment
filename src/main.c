#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "module.h"



int main(int argc, char const *argv[])
{
	char command_in[MAX_BUFF_LEN];
	uint8_t len = 0;

	len = command_read(command_in);

	printf("cmd = %s\nlen = %d\n", command_in, len);


	return 0;
}