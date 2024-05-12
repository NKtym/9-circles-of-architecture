#include "assemb.h"

int assmb_command(char *str)
{
	int ret;

	if (strcmp(str, "READ") == 0)
		ret = 10;
	else if (strcmp(str, "WRITE") == 0)
		ret = 11;
	else if (strcmp(str, "LOAD") == 0)
		ret = 20;
	else if (strcmp(str, "STORE") == 0)
		ret = 21;
	else if (strcmp(str, "ADD") == 0)
		ret = 30;
	else if (strcmp(str, "SUB") == 0)
		ret = 31;
	else if (strcmp(str, "DIVIDE") == 0)
		ret = 32;
	else if (strcmp(str, "MUL") == 0)
		ret = 33;
	else if (strcmp(str, "JUMP") == 0)
		ret = 40;
	else if (strcmp(str, "JNEG") == 0)
		ret = 41;
	else if (strcmp(str, "JZ") == 0)
		ret = 42;
	else if (strcmp(str, "HALT") == 0)
		ret = 43;
	else if (strcmp(str, "OR") == 0)
		ret = 53;
    else if (strcmp(str, "XOR") == 0)
		ret = 54;
	else
		ret = -1;
	
	return ret;
}