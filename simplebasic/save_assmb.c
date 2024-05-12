#include "basic.h"

void save_assmb(FILE *file, struct memory_bs* memory, int code_pos, int val_pos)
{
	int i;

	for (i = 0; i < code_pos; i++) {
		switch (memory[i].command) {
			case 10:
				fprintf(file, "%02d READ %d\n", i, memory[i].operand);
			break;
			
			case 11:
				fprintf(file, "%02d WRITE %d\n", i, memory[i].operand);
			break;
			
			case 20:
				fprintf(file, "%02d LOAD %d\n", i, memory[i].operand);
			break;
			
			case 21:
				fprintf(file, "%02d STORE %d\n", i, memory[i].operand);
			break;
			
			case 30:
				fprintf(file, "%02d ADD %d\n", i, memory[i].operand);
			break;
			
			case 31:
				fprintf(file, "%02d SUB %d\n", i, memory[i].operand);
			break;
			
			case 32:
				fprintf(file, "%02d DIVIDE %d\n", i, memory[i].operand);
			break;
			
			case 33:
				fprintf(file, "%02d MUL %d\n", i, memory[i].operand);
			break;
			
			case 40:
				fprintf(file, "%02d JUMP %d\n", i, memory[i].operand);
			break;
			
			case 41:
				fprintf(file, "%02d JNEG %d\n", i, memory[i].operand);
			break;
			
			case 42:
				fprintf(file, "%02d JZ %d\n", i, memory[i].operand);
			break;
			
			case 43:
				fprintf(file, "%02d HALT %d\n", i, memory[i].operand);
			break;
		}
	}
	for (i = val_pos+1; i < 100; i++) {
		if (memory[i].command != 0) {
			fprintf(file, "%02d = +%04x\n", i, memory[i].command);
		}
	}
}