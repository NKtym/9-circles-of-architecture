#pragma once
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum colors { // Перечислимый тип, описывающий цвета терминала 
    BLACK = 30, 
    RED, 
    GREEN, 
    YELLOW, 
    BLUE, 
    MAGENTA, 
    CYAN, 
    WHITE 
}; 

int mt_clrscr (void);
int mt_gotoXY (int, int);
int mt_getscreensize (int * rows, int * cols);
int mt_setfgcolor (enum colors);
int mt_setbgcolor (enum colors);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);
void swap(int *x, int* y);