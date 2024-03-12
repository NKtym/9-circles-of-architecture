#include <mySimpleComputer.h>

int
sc_memoryGet (int address, int *value)
{
  if (address > MEMORYSIZE || address < EMPTYMEMORY)
    {
      printf ("Вы вышли за границы оперативной памяти\n");
      return -1;
    }
  *value = ram[address];
  return 0;
}