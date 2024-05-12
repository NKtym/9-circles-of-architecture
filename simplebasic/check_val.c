#include "basic.h"

int check_val(char *str)
{
	if ((str[0] >= 'A') && (str[0] <= 'Z')) {
		if (str[1] == '\0')
			return 0;
		else
			return -1;
	}
	else
		return -1;
}