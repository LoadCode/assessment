#include <stdio.h>
#include <stdint.h>
#include "app.h"
#include "serial_port.h"
#include "module.h"




int main(int argc, char const *argv[])
{
	bool_t value = true;
	while(value)
	{
		printf("Hola a todos\n");
		value = !value;
	}
	printf("Hemos terminado aqui\n");
	return 0;
}