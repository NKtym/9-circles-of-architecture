#include "assemb.h"

int main(){
    char buf[256], line[256];
	char* add_mem = calloc(MEMORYSIZE, 1);
	FILE *input, *output;
	int value, addr, line_cnt = 1;
	int err;
	int flag_err = 0;
    char asm_filename[256];
    char binar_filename[256];
    scanf("%s",&asm_filename);
	strcat(asm_filename,".sa");
    scanf("%s",&binar_filename);
	strcat(binar_filename,".bin");
    input = fopen(asm_filename, "rb");
    if (input == NULL) {
        return -1;
	}
    output = fopen(binar_filename, "wb");
	if (output == NULL) {
        return -1;
	}
	sc_memoryInit();
	for (int i = 0; i < 128; i++){
        if (sc_memorySet (i, 0) != 0)
        	return -1;
    }
    while (fgets(line, 256, input)) {
		strcpy(buf, line);
		err = read_assemb(buf, &addr, &value);
		if (err == 0) {
			if (add_mem[addr] == 0) {
				ram[addr] = value;
			}
			else {
				return -1;
			}
		}
		else{
			return -1;
		}
		line_cnt++;
	}
	fwrite(ram, 1, MEMORYSIZE*sizeof(int), output);
	fclose(input);
	fclose(output);
	return 0;
}