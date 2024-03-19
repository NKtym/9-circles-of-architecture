#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (21, 3);
  printf ("10: %d | ", value);
  printf ("8: %o | ", value);
  printf ("16: %x | ", value);
  printf ("2: %b", value);
  fflush (stdout);
}