#include <mySimpleComputer.h>

int
sc_memorySet (int address, int value)
{
  if (address > MEMORYSIZE || address < EMPTYMEMORY)
    {
      printf ("Вы вышли за границы оперативной памяти\n");
      return -1;
    }
  if (value < INT_MIN || value > INT_MAX)
  {
    return -1;
  }
  // /if(value<0){
  //   value = ~(value)+1;
  //   value = value | 16384; 
  //}
  ram[address] = value;
  return 0;
}