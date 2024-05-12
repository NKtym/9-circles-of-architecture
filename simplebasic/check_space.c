#include "basic.h"

int check_space(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\0') || (c == '\n'))
		return 0;
	else
		return -1;
}