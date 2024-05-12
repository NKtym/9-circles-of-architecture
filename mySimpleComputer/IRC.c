#include "mySimpleComputer.h"

void IRC(int signum){
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
    }
    mt_gotoXY(2,2);
    rk_mytermregime(1,0,0,0,1);
}