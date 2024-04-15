#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCommand (void)
{
  char* header = "Command";
  bc_box(5,122,7,132,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  mt_gotoXY (6, 124);
  printf("        ");
  fflush (stdout);
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[cnt_command], sign, command, operand);
  mt_gotoXY (6, 124);
  if (sc_commandValidate (ram[cnt_command]) == -1)
    printf ("!");
  else
    printf ("+%x | %x", *command, *operand);
  free (sign);
  free (command);
  free (operand);
  fflush (stdout);
}