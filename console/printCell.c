#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  mt_gotoXY ((address % 10) * 2 + 1, 10 * (address / 12));
  mt_setfgcolor (fg);
  mt_setbgcolor (bg+10);
  printf ("+%04x", ram[address]);
  fflush (stdout);
}