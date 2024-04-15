#include <myTerm.h>

void printKey(){
    char* header = "Keys";
    bc_box(20, 142, 27, 166,GREEN,BLACK,header,GREEN,BLACK);
    fflush (stdout);
    mt_gotoXY (21, 143);
    printf("l - load s - save");
    fflush (stdout);
    mt_gotoXY (22, 143);
    printf("i - reset ESC - exit");
    fflush (stdout);
    mt_gotoXY (23, 143);
    printf("ENTER - update ram");
    fflush (stdout);
    mt_gotoXY (24, 143);
    printf("F5 - update accumulator");
    fflush (stdout);
    mt_gotoXY (25, 143);
    printf("F6 - update counter");
    fflush (stdout);
    mt_gotoXY (26, 143);
    printf("r - run");
    fflush (stdout);
}