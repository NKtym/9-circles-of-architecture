#include "basic.h"

int transform_rpn(char *rpn, char *a)
{
	struct stack_bs *stk = NULL;
	int i, cnt;
	i = 0;
	cnt = 0;
	while(a[i] != '\0' && a[i] != '\n') {
		if(a[i] == ')') {
			while((stk->c) != '(')
				rpn[cnt++]=stack_pop(&stk);
			stack_pop(&stk);
		}
		if(a[i] >= 'A' && a[i] <= 'Z')
			rpn[cnt++] = a[i];
		if(a[i] >= '0' && a[i] <= '9')
		 	rpn[cnt++] = a[i];
		if(a[i] == '('){
			stk = stack_push(stk, '(');
			if(stk == NULL)
				return -1;
		}
		if(a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
			if(stk == NULL)
				stk = stack_push(stk, a[i]);
			else
				if(priority(stk->c) < priority(a[i]))
					stk = stack_push(stk, a[i]);
				else {
					while((stk != NULL) && (priority(stk->c) >= priority(a[i])))
						rpn[cnt++] = stack_pop(&stk); 
					stk = stack_push(stk, a[i]);
				}
		}
		i++;
	}
	while(stk != NULL)
		rpn[cnt++] = stack_pop(&stk);
	rpn[cnt] = '\0';
	return 0;
}