#include "basic.h"

int char_val[26];
int stack_addr[100];
struct b_label strnums[100];
struct memory_bs memory[100];
int code_pos = 0, val_pos = 99, strnum_pos = 0;
int strnum_pos_max = 0;

int get_val_addr(char c)
{
	if ((c >= 'A') && (c <= 'Z')) {
		if (char_val[c-'A'] < 0) {
			char_val[c-'A'] = val_pos;
			memory[val_pos].is_val = 1;
			memory[val_pos].command = 0;
			val_pos--;
		}
		return char_val[c-'A'];
	}
	else
		return -1;
}

int add_cnt(int n)
{
	memory[val_pos].is_val = 1;
	memory[val_pos].command = n;
	val_pos--;
	return val_pos+1;
}

int get_stack_addr(int n)
{
	if (stack_addr[n] < 0) {
		stack_addr[n] = val_pos;
		memory[code_pos].is_val = 1;
		memory[code_pos].command = 0;
		val_pos--;
	}
	return stack_addr[n];
}

int read_rpn(char *rpn, int val)
{
	int i = 0;
	int deepness = 0;
	int addr;
	int val1, val2;
	int cnt;
	
	while (rpn[i] != '\0') {
		if ((rpn[i] >= 'A') && (rpn[i] <= 'Z')) {
			addr = get_stack_addr(deepness);
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 20;
			memory[code_pos].operand = get_val_addr(rpn[i]);
			code_pos++;
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 21;
			memory[code_pos].operand = addr;
			code_pos++;
			deepness++;
		}
		if ((rpn[i] >= '0') && (rpn[i] <= '9')) {
		 	sscanf(rpn+i, "%d", &cnt);
			printf("Hello\n");
			printf("%d\n", cnt);
			addr = get_stack_addr(deepness);
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 20;
		 	memory[code_pos].operand = add_cnt(cnt);
			code_pos++;
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 21;
			memory[code_pos].operand = addr;
			code_pos++;
			deepness++;
		}
		if ((rpn[i] == '+') || (rpn[i] == '-') || (rpn[i] == '*') || (rpn[i] == '/')) {
			if (deepness < 2) {
				return -1;
			}
			val1 = get_stack_addr(deepness - 1);
			val2 = get_stack_addr(deepness - 2);
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 20;
			memory[code_pos].operand = val2;
			code_pos++;
			switch (rpn[i]) {
				case '+':
					memory[code_pos].is_val = 0;
					memory[code_pos].command = 30;
					memory[code_pos].operand = val1;
					code_pos++;
					break;
				
				case '-':
					memory[code_pos].is_val = 0;
					memory[code_pos].command = 31;
					memory[code_pos].operand = val1;
					code_pos++;
					break;
				
				case '/':
					memory[code_pos].is_val = 0;
					memory[code_pos].command = 32;
					memory[code_pos].operand = val1;
					code_pos++;
					break;
				
				case '*':
					memory[code_pos].is_val = 0;
					memory[code_pos].command = 33;
					memory[code_pos].operand = val1;
					code_pos++;
					break;
			}
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 21;
			memory[code_pos].operand = val2;
			code_pos++;
			deepness--;
		}
		i++;
	}
	addr = get_stack_addr(0);
	memory[code_pos].is_val = 0;
	memory[code_pos].command = 20;
	memory[code_pos].operand = addr;
	code_pos++;
	memory[code_pos].is_val = 0;
	memory[code_pos].command = 21;
	memory[code_pos].operand = val;
	code_pos++;
	return 0;
}

int read_bsc(char *str, char* command)
{
	char *tmp;
	char t[256];
	char rpn[256];
	int read_n, strnum;
	int if_val1, if_val2;
	int jamp, num;
	int prior;
	int val;
	
	if (strcmp(command, "INPUT") == 0){
			if (str[0]>='A' && str[0]<='Z') {
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 10;
				memory[code_pos].operand = get_val_addr(str[0]);
				code_pos++;
			}
			else {
				return -1;
			}
	}
		
	else if(strcmp(command, "OUTPUT") == 0){
			if (str[0]>='A' && str[0]<='Z') {
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 11;
				memory[code_pos].operand = get_val_addr(str[0]);
				code_pos++;
			}
			else {
				return -1;
			}
	}

	else if(strcmp(command, "GOTO") == 0){
		read_n = sscanf(str, "%d", &strnum);
		if (read_n == 1) {
			int addr = -1;
			for (int i = 0; i < strnum_pos_max; i++) {
				if (strnums[i].label == strnum)
					addr = strnums[i].pos;
			}
			memory[code_pos].is_val = 0;
			memory[code_pos].command = 40;
			memory[code_pos].operand = addr;
			code_pos++;
		}
		else  {
			return -1;
		}
	}
		
	else if(strcmp(command, "END") == 0 || strcmp(command, "END\n") == 0 ){
		memory[code_pos].is_val = 0;
		memory[code_pos].command = 43;
		memory[code_pos].operand = 0;
		code_pos++;
	}
		
	else if(strcmp(command, "IF") == 0){
		tmp = partition_str(t, str);
		if (check_val(t) == 0) {
			if_val1 = get_val_addr(t[0]);
		}
		else if (sscanf(t, "%d", &num) == 1) {
	 		if_val1 = add_cnt(num);
	 	}
		else {
			return -1;
		}
			
		tmp = partition_str(t, tmp);
		if (strcmp(t, "<") == 0)
			prior = 1;
		else if (strcmp(t, ">") == 0)
			prior = 2;
		else if (strcmp(t, "=") == 0)
			prior = 3;
		else {
			return -1;
		}
			
		tmp = partition_str(t, tmp);
		if (check_val(t) == 0) {
			if_val2 = get_val_addr(t[0]);
		}
		else if (sscanf(t, "%d", &num) == 1) {
			if_val2 = add_cnt(num);
		}
		else {
			return -1;
		}
			
		switch (prior) {
			case 1:
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 20;
				memory[code_pos].operand = if_val1;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 31;
				memory[code_pos].operand = if_val2;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 41;
				memory[code_pos].operand = code_pos+2;
				code_pos++;
				break;
				
			case 2:
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 20;
				memory[code_pos].operand = if_val2;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 31;
				memory[code_pos].operand = if_val1;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 41;
				memory[code_pos].operand = code_pos+2;
				code_pos++;
				break;
				
			case 3:
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 20;
				memory[code_pos].operand = if_val1;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 31;
				memory[code_pos].operand = if_val2;
				code_pos++;
				memory[code_pos].is_val = 0;
				memory[code_pos].command = 42;
				memory[code_pos].operand = code_pos+2;
				code_pos++;
				break;
		}
		jamp = code_pos;
		memory[code_pos].is_val = 0;
		memory[code_pos].command = 40;
		memory[code_pos].operand = 0;
		code_pos++;
		tmp = partition_str(t, tmp);
		if (strcmp(t,"LET")!= 0 && strcmp(t,"REM")!= 0 && strcmp(t,"INPUT")!= 0 && strcmp(t,"OUTPUT")!= 0 && strcmp(t,"GOTO")!= 0 && strcmp(t,"END")!= 0) {
			return -1;
		}
		read_bsc(tmp, t);
		memory[jamp].operand = code_pos;
	}
			
	else if(strcmp(command, "LET") == 0){
				tmp = partition_str(t, str);
				if (!check_val(t)) {
					val = get_val_addr(t[0]);
				}
				else {
					return -1;
				}
				tmp = partition_str(t, tmp);
				if (strcmp(t, "=") != 0) {
					return -1;
				}
				if(transform_rpn(rpn, tmp) == -1){
					return -1;
				}
				if(read_rpn(rpn, val) == -1){
					return -1;
				}
	}
	return 0;
}

int main()
{
	FILE *input, *output, *inputtmp;
	char asm_filename[256];
	char basic_filename[256];
	char line[256], command[256];
	char *str;
	int strnum;
	scanf("%s",basic_filename);
	strcat(basic_filename, ".bas");
	scanf("%s",asm_filename);
	strcat(asm_filename, ".sa");
    input = fopen(basic_filename, "rb");
	if (input == NULL) {
        return -1;
	}
	inputtmp = fopen(basic_filename, "rb");
	if (inputtmp == NULL) {
        return -1;
	}
    output = fopen(asm_filename, "wb");
	if (output == NULL) {
		return -1;
	}
	
	for (int i = 0; i < 26; i++)
		char_val[i] = -1;
	for (int i = 0; i < 100; i++)
		stack_addr[i] = -1;
	while (fgets(line, 256, inputtmp)) {
		str = get_strnum_command(line, &strnum, command);
		if (str == NULL) {
			return -1;
		}
		strnums[strnum_pos_max].label = strnum;
		strnums[strnum_pos_max].pos = code_pos;
		strnum_pos_max++;
		read_bsc(str, command);
	}
	code_pos = 0;
	while (fgets(line, 256, input)) {
		str = get_strnum_command(line, &strnum, command);
		if (str == NULL) {
			return -1;
		}
		strnums[strnum_pos].label = strnum;
		strnums[strnum_pos].pos = code_pos;
		strnum_pos++;
		read_bsc(str, command);
	}
	save_assmb(output, memory, code_pos, val_pos);
	fclose(output);
	fclose(input);
	return 0;
}