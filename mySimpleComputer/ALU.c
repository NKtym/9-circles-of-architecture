#include "mySimpleComputer.h"

int ALU(int command, int operand)
{

	switch (command) {
		case 0x30: /* ADD */
			accum += ram[operand];
			break;
			
		case 0x31: /* SUB */
			accum -= ram[operand];
			break;
		
		case 0x32: /* DIV */
			if (ram[operand] != 0)
				accum /= ram[operand];
			else {
				sc_regSet(1, 1);
				return -1;
			}
			break;

        case 0x33: /* MUL */
			accum *= ram[operand];
			break;
	}
	if ((accum > 0x7FFF) || (accum < 0)) {
		accum &= 0x7FFF;
		sc_regSet(0, 1);
	}
	else
		sc_regSet(0, 0);
}
