#include "mySimpleComputer.h"

void usrsig_handler(int sig)
{
	sc_accumulatorSet(0);
	printAccumulator();
	for (int i = 0; i < 128; i++){
        if (sc_memorySet (i, 0) != 0)
            return -1;
    }
    for (int i = 0; i < 128; i++)
        printCell (i, GREEN, BLACK + 10);
	sc_icounterSet(0);
	printCounters();
	printCommand();
}