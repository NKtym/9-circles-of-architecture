#include "basic.h"

char *partition_str(char *t, char *str)
{
	int i;
	
	for (i = 0; (str[i] == ' ') || (str[i] == '\t'); i++);
	str += i;
	for (i = 0; check_space(str[i]) != 0; i++) {
		t[i] = str[i];
	}
	t[i] = '\0';
	
	return str+i;
}