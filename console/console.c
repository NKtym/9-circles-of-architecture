#include <mySimpleComputer.h>
#include <myTerm.h>

int
main ()
{
  if (isatty (1))
    {
      int cols, rows;
      if (mt_getscreensize (&rows, &cols) != 0)
        return -1;
      if (cols < 100 && rows < 20)
        return -1;
      sc_memoryInit ();
      sc_regInit ();
      sc_accumulatorInit ();
      sc_icounterInit ();
      for (int i = 0; i < 128; i++)
        {
          if (sc_memorySet (i, i+1280) != 0)
            {
              return -1;
            }
        }
      sc_regSet (1, 1);
      sc_regSet (2, 1);
      sc_regSet (5, 1);
      sc_accumulatorSet (5093);
      sc_icounterSet (15);
      mt_clrscr ();
      for (int i = 0; i < 127; i++)
        printCell (i, GREEN, BLACK+10);
      mt_setdefaultcolor ();
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
      printDecodedCommand (ram[78]);
      printCell (78, GREEN, BLACK+10);
      mt_setdefaultcolor ();
      for (int i = 0; i < 7; i++)
        printTerm (i * 20 + 1, 1);
      mt_gotoXY (40, 0);
      return 0;
    }
  return -1;
}