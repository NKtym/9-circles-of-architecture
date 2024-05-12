#pragma once
#include "mySimpleComputer.h"
#include <string.h>

struct b_label {
	int label;
	int pos;
};

struct memory_bs {
	int is_val;
	int command;
	int operand;
};

struct stack_bs {
	char c;
	struct stack_bs *next;
};

char *get_strnum_command(char *str, int *strnum, char *keyword);
int check_val(char *str);
int check_space(char c);
char *partition_str(char *t, char *str);
void save_assmb(FILE *file, struct memory_bs* memory, int code_pos, int val_pos);
struct stack_bs *stack_push(struct stack_bs *head, char a);
char stack_pop(struct stack_bs **head);
int priority(char c);
int transform_rpn(char *rpn, char *a);