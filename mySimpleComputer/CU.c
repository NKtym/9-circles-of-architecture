#include "mySimpleComputer.h"
#include "myReadkey.h"

void CU(){
    int operand,read,sign,command;
    int tmp;
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
                    // if(sc_memorySet (operand, read+ 1280)!=0){
                    //     sc_regSet(2, 1);
                    //     printFlags ();
                    //     break;
                    // }
                     if(sc_memorySet (operand, read)!=0){
                        sc_regSet(2, 1);
                        printFlags ();
                        break;
                    }
                    printCell(operand,GREEN,BLACK);
                    update_cache(operand);
                    printCache();
                    break;
                    
                case 11:                   
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
                    tmp = check_cache(operand);
                    if(tmp != -1){
                        mt_gotoXY (22, 123);
                        printf("+%04x",tmp);
                        fflush(stdout);
                    }
                    else{
                        mt_gotoXY (22, 123);
                        printf("+%04x",ram[operand]);
                        fflush(stdout);
                        printCache();
                    }
                    break;
                
                case 20:
                    tmp = check_cache(operand);
                    if(tmp != -1){
                        sc_accumulatorSet(tmp);
                        printAccumulator();
                    }
                    else{
                        sc_accumulatorSet(ram[operand]);
                        printAccumulator();
                        printCache();
                    }
                    break;
                
                case 21:
                    sc_memorySet(operand,accum);
                    update_cache(operand);
                    printCache();
                    printCell(operand,GREEN,BLACK);
                    break;
                
                case 40:
                    sc_icounterSet(operand-1);
                    printCounters();
                    break;
                
                case 41:
                    if (accum<0)
                        sc_icounterSet(operand-1);
                    printCounters();
                    break;
                    
                case 42:
                    if (accum == 0)
                        sc_icounterSet(operand-1);
                    printCounters();
                    break;
                
                case 43:
                    sc_regSet(3, 1);
                    printFlags ();
                    break;
                case 53:
                    tmp = check_cache(operand);
                    if(tmp != -1){
                        sc_accumulatorSet(tmp|accum);
                        printAccumulator();
                    }
                    else{
                        sc_accumulatorSet(ram[operand]|accum);
                        printAccumulator();
                        printCache();
                    }
                    sc_accumulatorSet(ram[operand]|accum);
                    printAccumulator();
                    break;
                case 54:
                    tmp = check_cache(operand);
                    if(tmp != -1){
                        sc_accumulatorSet(tmp^accum);
                        printAccumulator();
                    }
                    else{
                        sc_accumulatorSet(ram[operand]^accum);
                        printAccumulator();
                        printCache();
                    }
                    break;
                default:
                    sc_regSet(3, 1);
                    printFlags ();
                    break;
        }
    }
    cnt_command++;
}