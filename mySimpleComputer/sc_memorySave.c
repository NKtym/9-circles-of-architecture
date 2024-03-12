#include <mySimpleComputer.h>

int
sc_memorySave (char *filename)
{
  if (!filename)
    {
      printf ("Неверная передача имени файла\n");
      return -1;
    }
  FILE *f1 = fopen (filename, "wb");
  fwrite (ram, MEMORYSIZE, sizeof (int), f1);
  if (!f1)
    {
      printf ("Ошибка записи файла\n");
      return -1;
    }
  fclose (f1);
  return 0;
}