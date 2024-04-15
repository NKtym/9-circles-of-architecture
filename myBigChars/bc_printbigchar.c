#include <myBigChars.h> 
#include <myTerm.h>

int bc_printbigchar(int* big, int x, int y, enum colors fg_color, enum colors bg_color) { 
    if (x < 0 || x >= 200 || y < 0 || y >= 200) 
        return -1; 
    mt_gotoXY (x,y);
    mt_setfgcolor (fg_color);
    mt_setbgcolor (bg_color + 10);
    int fd = open ("/dev/tty", O_RDWR);
    write (fd, "\E(0", 3);
    int bits, value;
    for (int i = 0; i < 2; i++) { 
        bits = big[i];
        for (int j = 0; j < 4; j++) {
            for(int k = 0; k < 8; k++){
                value = (bits >> (8 * j + k)) & 1; 
                if(value == 0)
                    printf(" ");
                else{
                    printf("%c",ACS_CKBOARD); 
                }
                if(i==0)
                    mt_gotoXY(x+j+1,y+k+1);
                else
                    mt_gotoXY(x+j+5,y+k+1);
            }
            if(i==0)
                mt_gotoXY(x+j+1,y);
            else
                mt_gotoXY(x+j+5,y);
        } 
    } 
    fflush (stdout);
    write (fd, "\E(B", 3);
    close(fd);
    return 0;
}