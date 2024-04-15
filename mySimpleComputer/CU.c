#include "mySimpleComputer.h"

void CU(){
    int operand,read,sign,command;
	if (sc_commandDecode(ram[cnt_command],&sign, &command, &operand) != 0) {
		sc_regSet(4, 1);
		sc_regSet(3, 1);
        printFlags();
		return;
	}
	if ((operand < 0) && (operand >= MEMORYSIZE)) {
		sc_regSet(4, 1);
		sc_regSet(3, 1);
        printFlags ();
		return;
	}
	if ((command >= 30) && (command <= 33)) {
		if (ALU(command, operand) != 0)
			sc_regSet(3, 1);
            printFlags ();
	}
	else {
        switch (command) {
                case 10:
                    mt_gotoXY (21, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (22, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (23, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (21, 123);
                    printf("Запись ram:");
                    fflush(stdout);
                    mt_gotoXY (22, 123);
                    rk_readvalue(&read,4);
                    if(sc_memorySet (operand, read + 1280)!=0){
                        sc_regSet(2, 1);
                        printFlags ();
                        break;
                    }
                    printCell(operand,GREEN,BLACK);
                    break;
                    
                case 11: /* WRITE ?*/                    
                    mt_gotoXY (21, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (22, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (23, 123);
                    printf("             ");
                    fflush(stdout);
                    mt_gotoXY (21, 123);
                    printf("Вывод ram:");
                    fflush(stdout);
                    rk_readvalue(&read,4);
                    printTerm(read,1);
                    break;
                
                case 20: /* LOAD */
                    accum = ram[operand];
                    break;
                
                case 21: /* STORE */
                    ram[operand] = accum;
                    break;
                
                case 40: /* JUMP */
                    cnt_command = operand;
                    break;
                
                case 41: /* JNEG */
                    if (((accum >> 14) & 1) == 1)
                        cnt_command = operand;
                    break;
                    
                case 42: /* JZ */
                    if (accum == 0)
                        cnt_command = operand;
                    break;
                
                case 43:
                    sc_regSet(3, 1);
                    printFlags ();
                    break;
                case 53://!
                    sc_accumulatorSet(ram[operand]|accum);
                    printAccumulator();
                    break;
                case 54://!
                    sc_accumulatorSet(ram[operand]^accum);
                    printAccumulator();
                    break;
                default:
                    sc_regSet(3, 1);
                    printFlags ();
                    break;
        }
    }
    cnt_command++;
}