#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCounters (void)
{
  mt_gotoXY (5, 160);
  printf ("Counters: %d", cnt_command);
  fflush (stdout);
}