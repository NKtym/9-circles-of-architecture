#include <mySimpleComputer.h>

int
sc_accumulatorSet (int value)
{
  if (value > ACCUM_MAX || value < ACCUM_MIN)
    return -1;
  accum = value;
  return 0;
}