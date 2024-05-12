#include <mySimpleComputer.h>

int
sc_icounterSet (int value)
{
  if (value > COMMAND_MAX || value < COMMAND_MIN-1)
    return -1;
  cnt_command = value;
  return 0;
}