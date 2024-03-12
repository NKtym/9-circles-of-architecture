#include <mySimpleComputer.h>

int
sc_regSet (int register_num, int value)
{
  if (register_num < REGISTER_MIN || register_num > REGISTER_MAX)
    return -1;
  if (value != 0)
    flag = FLAG_SET (register_num);
  else
    flag = FLAG_CLEAR (register_num);
  return 0;
}