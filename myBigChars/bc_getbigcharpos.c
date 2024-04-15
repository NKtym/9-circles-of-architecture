#include <myBigChars.h>

int bc_getbigcharpos(int *big, int x, int y, int *value) { 
    if (x < 0 || x >= 8 || y < 0 || y >= 8) 
        return -1;
    int index = y * 8 + x;
    int k = (y>3)?1:0;
    *value = (*(big+k) >> index) & 1;
    return 0;
} 