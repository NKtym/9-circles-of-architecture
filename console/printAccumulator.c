#include <mySimpleComputer.h>
#include <myTerm.h>
#include <myBigChars.h>

void
printAccumulator (void)
{
  char* header = "Accum";
  bc_box(2,122,4,132,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  mt_gotoXY (3, 125);
  printf("     ");
  fflush (stdout);
  mt_gotoXY (3, 125);
  printf ("%d", accum);
  fflush (stdout);
}