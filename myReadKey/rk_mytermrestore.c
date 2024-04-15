#include <myReadkey.h> 

struct termios saved_termios;

int rk_mytermrestore() { 
    if (tcsetattr(STDIN_FILENO, TCSANOW, &saved_termios) == -1) 
        return -1; // Ошибка установки параметров терминала 
    return 0; 
}