#include <mySimpleComputer.h>
#include <myTerm.h>

void
printAccumulator (void)
{
  mt_gotoXY (1, 150);
  printf ("%d\n", accum);
  fflush(stdout);
}