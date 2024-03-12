#include <mySimpleComputer.h>

int flag;
int cnt_command;
int accum;
int *ram;

int
main ()
{
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  printf ("Установка произвольных значений в оперативной память:\n");
  for (int i = 1280; i < 1380; i += 10)
    {
      sc_memorySet (i - 1280, i);
    }
  int *value = calloc (128, sizeof (int));
  for (int i = 0; i < 100; i += 10)
    {
      sc_memoryGet (i, value);
      printDecodedCommand (*value);
      printf ("\n");
    }
  printf ("Пример задания ячейки памяти недопустимым значением:\n");
  printf ("%d\n\n", sc_memorySet (127, 1100));
  for (int i = 0; i < 5; i += 2)
    sc_regSet (i, 1);
  printFlags ();
  printf ("Недопустимымое значением flag:\n");
  printf ("%d\n\n", sc_regSet (-1, 3));
  sc_accumulatorSet (15);
  printf ("Вывод значение заданного аккумулятору\n");
  printf ("%d\n", accum);
  printf ("Недопустимымое значение accum:\n");
  printf ("%d\n\n", sc_accumulatorSet (-1));
  printf ("Вывод значение заданного cnt_command\n");
  sc_icounterSet (15);
  printf ("%d\n", cnt_command);
  printf ("Недопустимымое значение command:\n");
  printf ("%d\n\n", sc_icounterSet (-1));
  int *sign = malloc (sizeof (int));
  int *comand = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  ram[50] = 1822;
  printf ("декодировать значение произвольной ячейки памяти и значение "
          "аккумулятора\n");
  sc_commandDecode (ram[50], sign, comand, operand);
  printf ("%d %d %d\n", *sign, *comand, *operand);
  sc_accumulatorSet (1281);
  sc_commandDecode (accum, sign, comand, operand);
  printf ("%d %d %d\n", *sign, *comand, *operand);
  printf ("Закодировка команды и вывод её на экран\n");
  sc_commandEncode (0, 14, 30, value);
  printDecodedCommand (*value);
  free (value);
  return 0;
}