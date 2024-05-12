#include "mySimpleComputer.h"

int ALU(int command, int operand)
{
	int tmp;
	switch (command) {
		case 30:
			tmp = check_cache(operand);
            if(tmp != -1){
                accum += tmp;
				printAccumulator();
            }
            else{
            	accum += ram[operand];
				printAccumulator();
                printCache();
            }
			break;
			
		case 31:
			tmp = check_cache(operand);
            if(tmp != -1){
                accum -= tmp;
				printAccumulator();
            }
            else{
            	accum -= ram[operand];
				printAccumulator();
                printCache();
            }
			break;
		
		case 32:
			tmp = check_cache(operand);
            if(tmp != -1){
                if (tmp != 0)
					accum /= tmp;
				else {
					sc_regSet(1, 1);
					return -1;
				}
				printAccumulator();
            }
            else{
            	if (ram[operand] != 0)
					accum /= ram[operand];
				else {
					sc_regSet(1, 1);
					return -1;
				}
				printAccumulator();
                printCache();
            }
			break;

        case 33:
			tmp = check_cache(operand);
            if(tmp != -1){
                accum *= tmp;
				printAccumulator();
            }
            else{
            	accum *= ram[operand];
				printAccumulator();
                printCache();
            }
			break;
	}
	if ((accum > 0x7FFF) || (accum < 0)) {
		sc_regSet(0, 1);
	}
	else
		sc_regSet(0, 0);
}
