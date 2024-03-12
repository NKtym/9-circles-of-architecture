#include <mySimpleComputer.h>
#include <myTerm.h>
  
void
printCommand (void)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[cnt_command], sign, command, operand);
  printf ("ram[%d] = %d\n", cnt_command, ram[cnt_command]);
  mt_gotoXY (15, 150);
  if (sc_commandValidate (ram[cnt_command]) == -1)
    printf ("!");
  else
    printf ("+%x %x\n", *command, *operand);
  free (sign);
  free (command);
  free (operand);
  fflush (stdout);
}