#include <myBigChars.h> 
 
int bc_printA(char *str) { 
    if (str == NULL) 
        return -1; 
    while (*str != '\0') { 
        uint8_t byte = (uint8_t)*str;
        printf("%8b ",byte);
        str++;
    }
    return 0; 
}