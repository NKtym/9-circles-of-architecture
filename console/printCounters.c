#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCounters (void)
{
  mt_gotoXY (5, 150);
  printf ("%d\n", cnt_command);
  fflush (stdout);
}