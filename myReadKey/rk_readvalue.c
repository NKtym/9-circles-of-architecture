#include <myReadkey.h> 
 
int rk_readvalue(int *value, int timeout) { 
    if(!value)
        return -1;
    int fd; 
    char buf[timeout]; 
    rk_mytermregime(0,0,timeout,1,1);
    read(STDIN_FILENO,&buf,timeout);
    *value = atoi(buf);
    return 0;
}