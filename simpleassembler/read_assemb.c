#include "assemb.h"

int read_assemb(char *str, int *addr, int *value)
{
	char *ptr;
	int operand, command;
	int flag_assign = 0;
	
	ptr = strchr(str, ';');
	if (ptr != NULL)
		*ptr = '\0';
	ptr = strchr(str, '\n');
	if (ptr != NULL)
		*ptr = '\0';
	ptr = strtok(str, " \t");
	if (ptr == NULL)
		return -1;
	if (sscanf(ptr, "%d", addr) != 1) {
		return -1;
	}
	if ((*addr < EMPTYMEMORY) || (*addr > MEMORYSIZE))
		return -1;
	ptr = strtok(NULL, " \t");
	if (ptr == NULL)
		return -1;
	else{
        if (strcmp(ptr, "=") == 0)
            flag_assign = 1;
        else {
            command = assmb_command(ptr);
            if (command == -1)
                return -1;
        }
    }
	ptr = strtok(NULL, " \t");
	if (ptr == NULL)
		return -1;
	if (!flag_assign) {
		if (sscanf(ptr, "%d", &operand) != 1) {
			return -1;
		}
	}
	else {
		sscanf(ptr + 1, "%x", value);
	}
	if ((operand < OPERAND_MIN) || (operand > OPERAND_MAX))
		return -1;
	ptr = strtok(NULL, " \t");
	if (ptr != NULL)
		return -1;
	if (!flag_assign) {
		sc_commandEncode(0,command, operand, value);
	}
	return 0;
}