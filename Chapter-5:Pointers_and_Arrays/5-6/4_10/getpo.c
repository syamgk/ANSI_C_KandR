#include <stdio.h>
#include <ctype.h>
#include "calc.h"

//getop: get next operator or numeric operand
int getop(char* s)
{
	int i, c;
	static int lastc = 0;
	if (lastc == 0)
		c = getch();
	else {
		c = lastc;
		lastc = 0;
	}

	while ((*s = c ) == ' ' || c == '\t')
		c = getch();
	
	s[1] = '\0';
	i = 0;
	if (islower(c) && c != 'v') {
		while (islower(c = getch())) 
			*(++s) = c;
		*(++s) = '\0';
		if(c != EOF)
			lastc = c;  
		return FUNCTION;
	}
	if (isupper(c) || c == 'v') {
		if (isupper(c))
			*s = c - 'A';
		return VARIABLE;
	}
	if (!isdigit(c) && c != '.' && c != '-') //not a number
		return c;
	if (*s == '-') {
		if (isdigit(c = getch()) || c =='.')
			*(++s) = c;
		else {
			if (c != EOF)
				lastc = c;
			return '-';
		}
	}

	if (isdigit(c))   // collect integer part
		while (isdigit(*(++s) = c = getch()))
			;
	
	if (c == '.')	// collect fraction part
		while (isdigit(*(++s) = c = getch()))
			;
	
	*s = '\0';
	
	if (c != EOF)
		lastc = c;
	
	return NUMBER;
}


void function(char f[])
{
	double op2;

	if (strcmp(f, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(f, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(f, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	}
	else 
		printf("no function named \"%s\"\n",f);
}
