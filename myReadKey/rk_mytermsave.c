#include <myReadkey.h> 

int rk_mytermsave() { 
    if (tcgetattr(STDIN_FILENO, &saved_termios) == -1) 
        return -1; // Ошибка получения параметров терминала 
    return 0; 
} 