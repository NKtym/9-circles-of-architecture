#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address > MEMORYSIZE || address < EMPTYMEMORY)
    {
      printf ("Вы вышли за границы оперативной памяти\n");
      return -1;
    }
  if (value < INT_MIN || value > INT_MAX || sc_commandValidate (value) != 0)
    {
      printf ("Вы вышли за границу значения int\n");
      return -1;
    }
  ram[address] = value;
  return 0;
}