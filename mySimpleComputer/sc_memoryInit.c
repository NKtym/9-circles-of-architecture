#include <mySimpleComputer.h>

int
sc_memoryInit (void)
{
  ram = calloc (128, sizeof (int));
  return 0;
}