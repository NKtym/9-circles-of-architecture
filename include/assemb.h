#pragma once
#include "mySimpleComputer.h"

int assmb_command(char *str);
int read_assemb(char *str, int *addr, int *value);
int equal_assemb(char *str, int value);