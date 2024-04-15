#include "mySimpleComputer.h"

int ALU(int command, int operand)
{
	switch (command) {
		case 30:
			accum += ram[operand];
			printAccumulator();
			break;
			
		case 31:
			accum -= ram[operand];
			printAccumulator();
			break;
		
		case 32:
			if (ram[operand] != 0)
				accum /= ram[operand];
			else {
				sc_regSet(1, 1);
				return -1;
			}
			printAccumulator();
			break;

        case 33:
			accum *= ram[operand];
			printAccumulator();
			break;
	}
	if ((accum > 0x7FFF) || (accum < 0)) {
		sc_regSet(0, 1);
	}
	else
		sc_regSet(0, 0);
}
