#include "basic.h"

struct stack_bs *stack_push(struct stack_bs *head, char a)
{
	struct stack_bs *tmp = malloc(sizeof(struct stack_bs));
	if(tmp == NULL) {
		return NULL;
	}
	tmp->c = a;
	tmp->next = head;
	return tmp;
}