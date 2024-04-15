#include <mySimpleComputer.h>
#include <myTerm.h>

void
printTerm (int address, int input)
{
  char* header = "IN--OUT";
  bc_box(20, 122, 24, 138,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  int tmp[3];
  int addr[3];
  tmp[1] = ram[address];
  addr[1] = address;
  if (address == 0)
    {
      tmp[0] = ram[127];
      addr[0] = 127;
    }
  else
    {
      tmp[0] = ram[address - 1];
      addr[0] = address - 1;
    }
  if (address == 127)
    {
      tmp[2] = ram[0];
      addr[2] = 0;
    }
  else
    {
      tmp[2] = ram[address + 1];
      addr[2] = address + 1;
    }
  for (int i = 0; i < 6; i++)
    {
      mt_gotoXY (21, 123);
      printf ("prev: +%x", tmp[0]);
      fflush (stdout);
      mt_gotoXY (23, 123);
      printf ("next: +%x", tmp[2]);
      fflush (stdout);
      if (input)
        {
          mt_gotoXY (22, 123);
          printf ("addr %d > +%x", addr[1], tmp[1]);
          fflush (stdout);
        }
      else
        {
          mt_gotoXY (22, 123);
          fflush (stdout);
          printf ("> ");
          scanf ("%d", &(ram[address]));
        }
      fflush (stdout);
    }
    sleep (1);
}