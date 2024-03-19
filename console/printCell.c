#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  mt_setfgcolor (fg);
  mt_setbgcolor (bg + 10);
  mt_gotoXY ((address % 10) * 2 + 1, 10 * (address / 12));
  printf ("+%04x", ram[address]);
  fflush (stdout);
}