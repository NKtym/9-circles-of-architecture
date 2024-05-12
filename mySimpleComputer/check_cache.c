#include "mySimpleComputer.h"

int check_cache(int operand){
    int flag = 0;
    int cnt = 0;
    for(int i = 0; i < CACHE_LINES; i++){
        if(cache[i].number == (operand / 10)+1){
            cache[i].priority++;
            return cache[i].line[operand % 10];
        }
        else{
            if(cache[i].number > 0){
                flag = 2;
            }
            else{
                flag = 1;
                cnt = i;
                break;
            }
        }
    }
    if(flag == 1){
        cache[cnt].number = (operand/10)+1;
        if (cache[cnt].number != 12){
            for(int i = 0; i<CACHE_LINE; i++){
                cache[cnt].line[i]=ram[(operand/10)*10 + i];
            }
            return -1;
        }
        else{
            for(int i = 0; i<CACHE_LINE-2; i++){
                cache[cnt].line[i]=ram[(operand/10)*10 + i];
            }
            return -1;
        }
    }
    else if(flag == 2){
        int tmp = 1000;
        int num = 0;
        for(int i = 0; i < CACHE_LINES; i++){
            if(cache[i].priority<tmp){
                tmp = cache[i].priority;
                num = i;
            }
        }
        cache[num].number = (operand/10)+1;
        for(int i = 0; i<CACHE_LINE; i++){
            cache[num].line[i]=ram[(operand/10)*10 + i];
        }
        return -1;
    }
}