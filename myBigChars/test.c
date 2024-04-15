#include <stdio.h> 
#include <stdint.h> 
#include <unistd.h>
#include <fcntl.h>

int bc_bigcharread(int fd, int *big, int need_count) { 
    for (int i = 0; i < need_count * 2; ++i) { 
        read(fd, &big[i], sizeof(int)); 
    } 
}

int main(){
    int font_file;
    font_file = open("big_font.bin", O_RDWR);
    int big_font[18][2];
    bc_bigcharread(font_file,(int *)big_font,18);
    printf("%d ", big_font[0][0]);
    printf("%d", big_font[17][0]);
    return 0;
}