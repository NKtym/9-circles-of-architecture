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
      if (cols < 170 && rows < 30)
        return -1;
      sc_memoryInit ();
      sc_regInit ();
      sc_accumulatorInit ();
      sc_icounterInit ();
      for (int i = 0; i < 128; i++)
        {
          if (sc_memorySet (i, i + 1280) != 0)
            {
              return -1;
            }
        }
      sc_regSet (1, 1);
      sc_regSet (4, 1);
      sc_accumulatorSet (2004);
      sc_icounterSet (15);
      mt_clrscr ();
      for (int i = 0; i < 127; i++)
        printCell (i, GREEN, BLACK + 10);
      printCell (30, GREEN, BLACK + 10);
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
      printDecodedCommand (ram[30]);
      for (int i = 0; i < 128; i++)
        printTerm (i, 1);
      return 0;
    }
  return -1;
}