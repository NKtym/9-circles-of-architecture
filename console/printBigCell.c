#include <myBigChars.h>
#include <myTerm.h>
#include <mySimpleComputer.h>

void printBigCell(int cnt)
{
  char* header = "Big Char";
  bc_box(9,122,18,163,GREEN,BLACK,header,GREEN,BLACK);
  fflush (stdout);
  int font_file;
  font_file = open("big_font.bin", O_RDWR);
  int big_font[18][2];
  bc_bigcharread(font_file,(int *)big_font,18);
  bc_printbigchar(big_font[16], 9, 122, GREEN, BLACK);
  bc_printbigchar(big_font[ram[cnt]>>12], 9, 130, GREEN, BLACK);
  int tmp = ram[cnt];
  for(int i = 0; i<8; i++){
    tmp &= ~(1 << i);
  }
  for(int i = 12; i<16; i++){
    tmp &= ~(1 << i);
  }
  bc_printbigchar(big_font[tmp>>8], 9, 138, GREEN, BLACK);
  tmp = ram[cnt];
  for(int i = 0; i<4; i++){
    tmp &= ~(1 << i);
  }
  for(int i = 8; i<16; i++){
    tmp &= ~(1 << i);
  }
  bc_printbigchar(big_font[tmp>>4], 9, 146, GREEN, BLACK);
  tmp = ram[cnt];
  for(int i = 4; i<16; i++){
    tmp &= ~(1 << i);
  }
  bc_printbigchar(big_font[tmp], 9, 154, GREEN, BLACK);
  fflush (stdout);
}