#include <myReadkey.h>

int rk_readkey(enum keys *key) { 
    char c; 
    if (read(STDIN_FILENO, &c, 1) != 1) 
        return -1;
    switch (c) {
        case '\n': 
            *key = KEY_ENTER; 
            break; 
        case 27: // Escape sequence 
            if (read(STDIN_FILENO, &c, 1) != 1) 
                *key = KEY_ESC;
            else{
                if (read(STDIN_FILENO, &c, 1) != 1) 
                    return -1; // Ошибка чтения 
                switch (c) { 
                    case 'A': 
                        *key = KEY_UP; 
                        break; 
                    case 'B': 
                        *key = KEY_DOWN; 
                        break; 
                    case 'C': 
                        *key = KEY_RIGHT; 
                        break; 
                    case 'D': 
                        *key = KEY_LEFT;
                        break;
                    case '1':
                        if (read(STDIN_FILENO, &c, 1) != 1) 
                            return -1;
                        if(c == '7')
                            *key = KEY_F6; 
                        if(c == '5')
                            *key = KEY_F5; 
                        break; 
                    default: 
                        return -1;
                }
            }
            break; 
        case 'l': 
            *key = KEY_L; 
            break; 
        case 's': 
            *key = KEY_S; 
            break; 
        case 'i': 
            *key = KEY_I; 
            break; 
        case 'r':
            *key = KEY_R;
            break;
        case 't':
            *key = KEY_T;
            break;
        default: 
            return -1; // Неизвестная клавиша 
    } 
    return 0; 
}