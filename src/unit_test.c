#include <stdint.h>
#include "module.h"
#include "unit_test.h"

const char test_str[] = "read vol\b\b\bcurrent\r";
const char true_str[] = "read current";

bool_t read_serial(char *data)
{
	static uint8_t i = -1;
	i++;
	*data = test_str[i];
	return true;
}


