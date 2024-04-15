#include <mySimpleComputer.h>
#include <myTerm.h>
#include <myBigChars.h>
#include <myReadkey.h>

int
main ()
{
  if (isatty (1))
    {
      int cols, rows;
      if (mt_getscreensize (&rows, &cols) != 0)
        return -1;
      if (cols < 200 && rows < 50)
        return -1;
      int font_file;
      font_file = open("big_font.bin", O_RDWR);
      if(!font_file){
        return -1;
      }
      sc_memoryInit ();
      sc_regInit ();
      sc_accumulatorInit ();
      sc_icounterInit ();
      for (int i = 0; i < 128; i++)
      {
        if (sc_memorySet (i, i + 1280) != 0)
          return -1;
      }
      sc_regSet (3, 1);
      sc_accumulatorSet (2004);
      sc_icounterSet (0);
      mt_clrscr ();
      char* header = "Random Access Memory";
      bc_box(1, 1, 21, 115,GREEN,BLACK,header,GREEN,BLACK);
      fflush (stdout);
      for (int i = 0; i < 128; i++)
        printCell (i, GREEN, BLACK + 10);
      printAccumulator ();
      printCounters ();
      printFlags ();
      printCommand ();
      printDecodedCommand (ram[0]);
      printBigCell(0);
      printKey();
      signal (SIGALRM, IRC);//
      signal (SIGUSR1, usrsig_handler);//
      for (int i = 0; i < 128; i++){
        printTerm (i, 1);
        if(printReadkey()!=0){
          return 0;
        }
        alarm (1);//
      }
      fclose(font_file);
      return 0;
    }
  return -1;
}