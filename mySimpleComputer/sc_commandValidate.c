#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if ((command >> 14) > SIGN_COMMAND || (command >> 7) > OPERATION_CODE_MAX
      || (command >> 7) < OPERATION_CODE_MIN)
    return -1;
  return 0;
}