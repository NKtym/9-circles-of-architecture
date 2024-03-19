#include <mySimpleComputer.h>
#include <myTerm.h>

void
printAccumulator (void)
{
  mt_gotoXY (2, 140);
  printf ("Accum: %d", accum);
  fflush (stdout);
}