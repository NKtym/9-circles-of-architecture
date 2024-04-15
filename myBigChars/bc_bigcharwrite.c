#include <myBigChars.h> // для write 
 
int bc_bigcharwrite(int fd, int *big, int count) { 
    if(!big){
        return -1;
    }
    for(int i = 0; i < count * 2; i++){
        write(fd, &big[i], sizeof(int));
    }
}