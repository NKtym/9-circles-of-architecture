#include "mySimpleComputer.h"

void T_RUN(int sig){
    int flagt;
    sc_regGet(4,&flagt);
    fflush(stdout);
    if(!flagt){
        CU();
        sc_regGet(4,&flagt);
        if(!flagt){
            alarm(2);
            printBigCell(cnt_command);
            printCounters();
            printCommand();
            printDecodedCommand(ram[cnt_command]);
        }
        sc_regSet(3,1);
        printFlags();
    }
    mt_gotoXY(2,2);
    rk_mytermregime(1,0,0,0,1);
}