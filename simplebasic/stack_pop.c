#include "basic.h"

char stack_pop(struct stack_bs **head)
{
	struct stack_bs  *tmp;
	char a;

	if(*head == NULL)
		return '\0';
	tmp = *head;
    a = tmp->c;
    *head = tmp->next;
	free(tmp);
    return a;
}