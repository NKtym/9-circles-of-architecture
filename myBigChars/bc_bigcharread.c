#include <myBigChars.h>
 
int bc_bigcharread(int fd, int *big, int need_count) { 
    for (int i = 0; i < need_count * 2; ++i) { 
        read(fd, &big[i], sizeof(int)); 
    } 
}