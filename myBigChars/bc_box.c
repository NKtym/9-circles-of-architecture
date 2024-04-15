#include <myTerm.h>
#include <myBigChars.h>

int bc_box(int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg, char *header, enum colors header_fg,
enum colors header_bg){
    mt_setfgcolor (box_fg);
    mt_setbgcolor (box_bg + 10);
    mt_gotoXY (x1,y1);
    int fd = open ("/dev/tty", O_RDWR);
    write (fd, "\E(0", 3);
    printf("l");
    for(int i = y1+1; i <= y2-1; i++){
        printf("q");
    }
    printf("k");
    fflush (stdout);
    for(int i = x1+1; i <= x2-1; i++){
        mt_gotoXY (i, y2);
        printf("x");
        fflush (stdout);
    }
    mt_gotoXY (x2, y2);
    printf("j");
    fflush (stdout);
    mt_gotoXY (x1, y1);
        for(int i = x1+1; i <= x2-1; i++){
        mt_gotoXY (i, y1);
        printf("x");
        fflush (stdout);
    }
    mt_gotoXY (x2, y1);
    printf("m");
    fflush (stdout);
    for(int i = y1+1; i <= y2-1; i++){
        printf("q");
    }
    fflush (stdout);
    write (fd, "\E(B", 3);
    int len = bc_strlen(header);
    if(header!=NULL && len!=0){
        mt_setfgcolor (header_fg);
        mt_setbgcolor (header_bg + 10);
        int shift = ((y2-y1)-len)/2;
        mt_gotoXY (x1,y1+shift+1);
        printf("%s", header);
    }
    close (fd);
}