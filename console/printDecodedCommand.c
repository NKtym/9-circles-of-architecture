#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  char* header = "Decoded";
  bc_box(23, 2, 25, 53,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  mt_gotoXY (24, 3);
  printf("                                                  ");
  fflush (stdout);
  mt_gotoXY (24, 3);
  printf ("10: %d | ", value);
  printf ("8: %o | ", value);
  printf ("16: %x | ", value);
  printf ("2: %b", value);
  fflush (stdout);
}