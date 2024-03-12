#include <mySimpleComputer.h>

int
sc_icounterGet (int *value)
{
  if (value == NULL)
    return -1;
  *value = cnt_command;
  return 0;
}