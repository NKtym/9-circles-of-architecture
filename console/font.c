#include <myBigChars.h>

int** font(int big_font[18][2]){
    for(int i=0; i<18; i++){
        switch (i)
        {
            case 0:
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[0], 1, j, 1);
                    bc_setbigcharpos(big_font[0], 6, j, 1);
                }
                for(int j=2; j<6; j++){
                    bc_setbigcharpos(big_font[0], j, 7, 1);
                    bc_setbigcharpos(big_font[0], j, 0, 1);
                }
                break;
            case 1:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[1], 3, j, 1);
                    bc_setbigcharpos(big_font[1], 4, j, 1);
                }
                break;
            case 2:
                for(int j=1; j<3; j++){
                    bc_setbigcharpos(big_font[2], 5, j, 1);
                    bc_setbigcharpos(big_font[2], 6, j, 1);
                }
                for(int j=4; j<7; j++){
                    bc_setbigcharpos(big_font[2], 1, j, 1);
                    bc_setbigcharpos(big_font[2], 2, j, 1);
                }
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[2], j, 0, 1);
                    bc_setbigcharpos(big_font[2], j, 3, 1);
                    bc_setbigcharpos(big_font[2], j, 7, 1);
                }
                break;
            case 3:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[3], 5, j, 1);
                    bc_setbigcharpos(big_font[3], 6, j, 1);
                }
                for(int j=1; j<5; j++){
                    bc_setbigcharpos(big_font[3], j, 0, 1);
                    bc_setbigcharpos(big_font[3], j, 3, 1);
                    bc_setbigcharpos(big_font[3], j, 7, 1);
                }
                break;
            case 4:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[4], 5, j, 1);
                    bc_setbigcharpos(big_font[4], 6, j, 1);
                }
                for(int j=1; j<5; j++){
                    bc_setbigcharpos(big_font[4], j, 3, 1);
                }
                for(int j=0; j<4; j++){
                    bc_setbigcharpos(big_font[4], 1, j, 1);
                    bc_setbigcharpos(big_font[4], 2, j, 1);
                }
                break;
            case 5:
                for(int j=0; j<3; j++){
                    bc_setbigcharpos(big_font[5], 1, j, 1);
                    bc_setbigcharpos(big_font[5], 2, j, 1);
                }
                for(int j=3; j<8; j++){
                    bc_setbigcharpos(big_font[5], 5, j, 1);
                    bc_setbigcharpos(big_font[5], 6, j, 1);
                }
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[5], j, 0, 1);
                    bc_setbigcharpos(big_font[5], j, 3, 1);
                    bc_setbigcharpos(big_font[5], j, 7, 1);
                }
                break;
            case 6:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[6], 1, j, 1);
                    bc_setbigcharpos(big_font[6], 2, j, 1);
                }
                for(int j=3; j<7; j++){
                    bc_setbigcharpos(big_font[6], j, 0, 1);
                    bc_setbigcharpos(big_font[6], j, 3, 1);
                    bc_setbigcharpos(big_font[6], j, 7, 1);
                }
                for(int j=4; j<7; j++){
                    bc_setbigcharpos(big_font[6], 5, j, 1);
                    bc_setbigcharpos(big_font[6], 6, j, 1);
                }
                break;
            case 7:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[7], 5, j, 1);
                    bc_setbigcharpos(big_font[7], 6, j, 1);
                }
                for(int j=1; j<5; j++){
                    bc_setbigcharpos(big_font[7], j, 0, 1);
                }
                break;
            case 8:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[8], 1, j, 1);
                    bc_setbigcharpos(big_font[8], 2, j, 1);
                    bc_setbigcharpos(big_font[8], 5, j, 1);
                    bc_setbigcharpos(big_font[8], 6, j, 1);
                }
                for(int j=3; j<5; j++){
                    bc_setbigcharpos(big_font[8], j, 0, 1);
                    bc_setbigcharpos(big_font[8], j, 3, 1);
                    bc_setbigcharpos(big_font[8], j, 7, 1);
                }
                break;
            case 9:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[9], 5, j, 1);
                    bc_setbigcharpos(big_font[9], 6, j, 1);
                }
                for(int j=1; j<5; j++){
                    bc_setbigcharpos(big_font[9], j, 0, 1);
                    bc_setbigcharpos(big_font[9], j, 4, 1);
                    bc_setbigcharpos(big_font[9], j, 7, 1);
                }
                for(int j=1; j<4; j++){
                    bc_setbigcharpos(big_font[9], 1, j, 1);
                    bc_setbigcharpos(big_font[9], 2, j, 1);
                }
                break;
            case 10:
                for(int j=1; j<8; j++){
                    bc_setbigcharpos(big_font[10], 1, j, 1);
                    bc_setbigcharpos(big_font[10], 2, j, 1);
                    bc_setbigcharpos(big_font[10], 5, j, 1);
                    bc_setbigcharpos(big_font[10], 6, j, 1);
                }
                for(int j=2; j<6; j++){
                    bc_setbigcharpos(big_font[10], j, 0, 1);
                    bc_setbigcharpos(big_font[10], j, 4, 1);
                }
                break;
            case 11:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[11], 1, j, 1);
                    bc_setbigcharpos(big_font[11], 2, j, 1);
                }
                for(int j=2; j<6; j++){
                    bc_setbigcharpos(big_font[11], j, 0, 1);
                    bc_setbigcharpos(big_font[11], j, 3, 1);
                    bc_setbigcharpos(big_font[11], j, 7, 1);
                }
                for(int j=1; j<3; j++){
                    bc_setbigcharpos(big_font[11], 6, j, 1);
                    bc_setbigcharpos(big_font[11], 7, j, 1);
                }
                for(int j=4; j<7; j++){
                    bc_setbigcharpos(big_font[11], 6, j, 1);
                    bc_setbigcharpos(big_font[11], 7, j, 1);
                }
                break;
            case 12:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[12], 1, j, 1);
                    bc_setbigcharpos(big_font[12], 2, j, 1);
                }
                for(int j=3; j<7; j++){
                    bc_setbigcharpos(big_font[12], j, 0, 1);
                    bc_setbigcharpos(big_font[12], j, 7, 1);
                }
                break;
            case 13:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[13], 1, j, 1);
                    bc_setbigcharpos(big_font[13], 2, j, 1);
                }
                for(int j=3; j<7; j++){
                    bc_setbigcharpos(big_font[13], j, 0, 1);
                    bc_setbigcharpos(big_font[13], j, 7, 1);
                }
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[13], 7, j, 1);
                    bc_setbigcharpos(big_font[13], 6, j, 1);
                }
                break;
            case 14:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[14], 1, j, 1);
                    bc_setbigcharpos(big_font[14], 2, j, 1);
                }
                for(int j=2; j<7; j++){
                    bc_setbigcharpos(big_font[14], j, 0, 1);
                    bc_setbigcharpos(big_font[14], j, 3, 1);
                    bc_setbigcharpos(big_font[14], j, 7, 1);
                }
                break;
            case 15:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[15], 1, j, 1);
                    bc_setbigcharpos(big_font[15], 2, j, 1);
                }
                for(int j=2; j<6; j++){
                    bc_setbigcharpos(big_font[15], j, 3, 1);
                    bc_setbigcharpos(big_font[15], j, 0, 1);
                }
                break;
            case 16:
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[16], 3, j, 1);
                    bc_setbigcharpos(big_font[16], 4, j, 1);
                }
                for(int j=1; j<7; j++){
                    bc_setbigcharpos(big_font[16], j, 3, 1);
                    bc_setbigcharpos(big_font[16], j, 4, 1);
                }
                break;
            case 17:
                for(int j=0; j<8; j++){
                    bc_setbigcharpos(big_font[17], 1, j, 1);
                    bc_setbigcharpos(big_font[17], 2, j, 1);
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

int main(){
    int font_file;
    font_file = open("big_font.bin", O_RDWR);
    if(!font_file){
        return -1;
    }
    int big_font[18][2];
    font(big_font);
    bc_bigcharwrite(font_file,(int *)big_font, 18);
    close(font_file);
    return 0;
}