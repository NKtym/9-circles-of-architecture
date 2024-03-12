#include <mySimpleComputer.h>

int
sc_regGet (int register_num, int *value)
{
  if (register_num < REGISTER_MIN || register_num > REGISTER_MAX
      || value == NULL)
    return -1;
  *value = FLAG_GET (register_num);
  return 0;
}