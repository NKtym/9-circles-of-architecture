#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCounters (void)
{
  char* header = "Count";
  bc_box(5, 136, 7, 146,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  mt_gotoXY (6, 140);
  printf ("     ");
  fflush (stdout);
  mt_gotoXY (6, 140);
  printf ("%d", cnt_command);
  fflush (stdout);
}