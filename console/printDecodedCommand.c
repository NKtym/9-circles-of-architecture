#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (41, 1);
  printf ("10: %d\n", value);
  printf ("8: %o\n", value);
  printf ("16: %x\n", value);
  printf ("2: %b\n", value);
  fflush(stdout);
}