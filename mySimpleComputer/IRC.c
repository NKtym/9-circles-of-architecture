#include "mySimpleComputer.h"

void IRC(int signum){
    int flagt;
    sc_regGet(4,&flagt);
    fflush(stdout);
    if(!flagt){
        CU();
        alarm(1);
    }
    mt_gotoXY(2,2);
    rk_mytermregime(1,0,0,0,1);
}