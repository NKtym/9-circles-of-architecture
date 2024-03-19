#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCommand (void)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[cnt_command], sign, command, operand);
  mt_gotoXY (5, 140);
  if (sc_commandValidate (ram[cnt_command]) == -1)
    printf ("!");
  else
    printf ("Command: +%x | %x", *command, *operand);
  free (sign);
  free (command);
  free (operand);
  fflush (stdout);
}