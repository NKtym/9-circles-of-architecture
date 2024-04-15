#include <myBigChars.h> 

int bc_setbigcharpos(int* big, int x, int y, int value){
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || value < 0 || value > 1) 
        return -1;
    int index;
    if(y>3){
        index = (y-4) * 8 + x;
    }
    else{
        index = y * 8 + x; // Вычисляем индекс в массиве 
    }
    int k = (y>3)?1:0;
    if (value == 0) 
        *(big+k) &= ~(1 << index); // Сбрасываем бит, если значение 0 
    else 
        *(big+k) |= (1 << index); // Устанавливаем бит, если значение 1 
    return 0; // Возвращаем 0 при успешном выполнении 
}