#include "mySimpleComputer.h"

struct caches cache[CACHE_LINES];

void
printCache ()
{
  char* header = "CPU Cache";
  bc_box(23,55,29,119,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  for (int i = 0; i < 5; i++)
    {
      mt_gotoXY (24 + i, 56);
      printf ("%d0:", cache[i].number);
      fflush (stdout);
      for (int j = 0; j < 10; j++)
        {
          mt_gotoXY (24 + i, 60 +  j * 6);
          if(cache[i].line[j]>-1)
            printf ("+%04X", cache[i].line[j]);
          else
            printf ("+%04X", cache[i].line[j]&0xFFFF);
          fflush(stdout);
        }
    }
}