#include <mySimpleComputer.h>
#include <myTerm.h>

void mt_swap(int *x, int* y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}