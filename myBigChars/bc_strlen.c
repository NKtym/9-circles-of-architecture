#include <myBigChars.h> 
 
int bc_strlen(char *str) { 
    if (str == NULL) 
        return 0; 
 
    int length = 0; 
    while (*str != '\0') { 
        uint8_t byte = (uint8_t)*str; 
        if ((byte >> 7) == 0) {
            length++; 
            str++; 
        } else if ((byte >> 5) == 0b110) {
            if (((uint8_t)*(str + 1) & 0b11000000) == 0b10000000) { 
                length++; 
                str += 2; 
            } else { 
                return 0; 
            } 
        } else if ((byte >> 4) == 0b1110) {
            if (((uint8_t)*(str + 1) & 0b11000000) == 0b10000000 && 
                ((uint8_t)*(str + 2) & 0b11000000) == 0b10000000) { 
                length++; 
                str += 3; 
            } else { 
                return 0;
            } 
        } else if ((byte >> 3) == 0b11110) {
            if (((uint8_t)*(str + 1) & 0b11000000) == 0b10000000 && 
                ((uint8_t)*(str + 2) & 0b11000000) == 0b10000000 && 
                ((uint8_t)*(str + 3) & 0b11000000) == 0b10000000) { 
                length++; 
                str += 4; 
            } else { 
                return 0;
            } 
        } else { 
            return 0;
        } 
    } 
    return length; 
}