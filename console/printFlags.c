#include <mySimpleComputer.h>

void
printFlags (void)
{
  char* header = "Flags";
  bc_box(2, 136, 4, 146,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  mt_gotoXY (3, 137);
  if (flag & 0x1)
    printf ("П ");
  else
    printf ("_ ");
  if (flag & 0x2)
    printf ("0 ");
  else
    printf ("_ ");
  if (flag & 0x4)
    printf ("М ");
  else
    printf ("_ ");
  if (flag & 0x8)
    printf ("Т ");
  else
    printf ("_ ");
  if (flag & 0x10)
    printf ("Е");
  else
    printf ("_");
  fflush (stdout);
}