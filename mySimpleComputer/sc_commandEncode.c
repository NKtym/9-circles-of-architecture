#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign != SIGN_COMMAND || command < OPERATION_CODE_MIN
      || command > OPERATION_CODE_MAX || value == NULL || operand < OPERAND_MIN
      || operand > OPERAND_MAX)
    return -1;
  *value = 0;
  (*value) = operand;
  *value = (*value) | command << 7;
  return 0;
}