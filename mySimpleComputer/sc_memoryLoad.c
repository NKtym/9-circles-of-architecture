#include <mySimpleComputer.h>

int
sc_memoryLoad (char *filename)
{
  if (!filename)
    {
      printf ("Неверная передача имени файла\n");
      return -1;
    }
  FILE *f1 = fopen (filename, "rb");
  if (!f1)
    {
      printf ("Ошибка чтения файла\n");
      return -1;
    }
  fread (ram, MEMORYSIZE, sizeof (int), f1);
  fclose (f1);
  return 0;
}