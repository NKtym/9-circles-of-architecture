#include "mySimpleComputer.h"

void update_cache(int operand){
        int tmp = 10;
        for(int i = 0; i < CACHE_LINES; i++){
            if(cache[i].number == (operand / 10)+1){
                if(cache[i].number == 12){
                    tmp = 8;
                }
                for(int j = 0; j<tmp; j++){
                    cache[i].line[j]=ram[(operand/10)*10 + j];
                }
            }
        }
}