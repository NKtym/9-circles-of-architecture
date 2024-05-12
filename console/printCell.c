#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  mt_setfgcolor (fg);
  mt_setbgcolor (bg + 10);
  mt_gotoXY ((address % 10) * 2 + 2, 9 * (address / 10)+2);
  if(ram[address]>-1)
    printf ("+%04x", ram[address]);
  else
    printf ("+%04x", ram[address]&0xFFFF);
  fflush (stdout);
}