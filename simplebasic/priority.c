#include "basic.h"

int priority(char c)
{
    switch(c)
    {
    	case '*':
			return 3;
    	case '/':
    		return 3;
    	case '-':
			return 2;
    	case '+':
    		return 2;
    	case '(':
    		return 1;
    }
}