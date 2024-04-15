#include <myReadkey.h> 

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint) { 
    struct termios term; 
    if (tcgetattr(STDIN_FILENO, &term) == -1) 
        return -1;//наверное можно будет убрать
    if (regime) {
        term.c_lflag &= ~(ICANON);
        if(echo)
            term.c_lflag |= ECHO;
        else
            term.c_lflag &= ~(ECHO);
        if(sigint)
            term.c_lflag |= ISIG; 
        else
            term.c_lflag &= ~(ISIG);
        term.c_cc[VMIN] = vmin; 
        term.c_cc[VTIME] = vtime; 
    } 
    else { 
        term.c_lflag |= ICANON;
        if(echo)
            term.c_lflag |= ECHO;
        else
            term.c_lflag &= ~(ECHO);
        if(sigint)
            term.c_lflag |= ISIG; 
        else
            term.c_lflag &= ~(ISIG);
    } 
    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) == -1) 
        return -1;
    return 0; 
}