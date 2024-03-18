#include <myTerm.h>

int mt_gotoXY(int x, int y) { 
    char buf[15]; 
    int len = sprintf(buf, "\E[%d;%dH", x, y); // формирование терминальной управляющей последовательности 
 
    int tty = open("/dev/tty", O_RDWR); // открытие терминала 
    if (tty == -1) { 
        perror("Error opening /dev/tty"); 
        return -1; 
    } 

    int bytes_written = write(tty, buf, len); // запись последовательности в терминал 
    if (bytes_written == -1) { 
        perror("Error writing to terminal"); 
        close(tty); 
        return -1; 
    } 
 
    close(tty); // закрытие терминала 
    fflush (stdout);
    return 0; 
}