#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

#define MAXOP 100   /* max size of operand or operator */
extern double val[];	// value stack

main()
{
	int i, temp_var;
	int type;
	double v, op2;
	char s[MAXOP];
	double variable[26];

	for (i = 0; i <= 26; i++)
		variable[i] = 0.0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop ());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: division by zero\n");
				break;
			case '%':                 // prints remainter
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else 
					printf("error: division by zero\n");
				break;
			case '=':
				pop();
				if (isupper(temp_var+'A')){
					printf("%d",(temp_var));
					variable[temp_var] = pop();
				}
				else 
					printf("%derror:no variable name\n",temp_var);
				break;
			case FUNCTION:
				function(s);
				break;
			case '\n':               // print and pop()
				printf("\t%.8g\n",v = pop());
				printf("\n'v'::%g\n",v);
				break;
			case VARIABLE:			 // prints variable
				if(s[0] != 'v') {
					push(variable[s[0]]);
					temp_var = s[0];
				}
				else
					push(v);
				break;
			case '|':				  // prints array val[];
				for( i = 0; val[i] != 0; i++)
					printf("%g, ",val[i]);
				printf("\n");
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
		if (!VARIABLE)
			temp_var = type;
	}
	return 0;
}


