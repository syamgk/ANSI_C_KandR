#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include<string.h> // for strlen()

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION 'f'
#define VARIABLE 'A' /* signal that a variable found*/
#define MAXVAL 100	// maximum depth of val stack
#define BUFSIZE 100

int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack
int buf[BUFSIZE];	// buffer getline() int for including (EOF = -1)
int bufp = 0;		// next free position in buf

int getop(char[]);
void push(double);
double pop(void);
void function(char[]);

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
			case '=':  					// assign value if prev stack is variable else error
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
				printf("\nv = %g\n",v);
				break;
			case VARIABLE:			 // prints variable
				if(s[0] != 'v') {
					push(variable[s[0]]);
					temp_var = s[0];
				}
				else          // push previously printed variable
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

// push: push f onto value stack
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

//getop: get next operator or numeric operand
int getop(char s[])
{
	int i, c;
	if (buf[bufp] == '\0')
		if (get_line() == EOF)
			return EOF;
		else 
			bufp = 0;
			
	while ((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	i = 0;
	if (islower(c) && c != 'v') {		// Function check(sin,exp..->all lwr case
		while (islower(c = buf[bufp++])) 
			s[++i] = c;
		s[++i] = '\0';
		if(c != EOF)
			bufp--;  
		return FUNCTION;
	}

	if (isupper(c) || c == 'v') {         // variables and temp_var(last printed)
		if (isupper(c))
			s[0] = c - 'A';
		return VARIABLE;
	}

	if (!isdigit(c) && c != '.' && c != '-') //not a number
		return c;
	if (s[0] == '-') {                 // -ve number
		if (isdigit(c = buf[bufp++]) || c =='.')
			s[++i] = c;
		else {
			if (c != EOF)
				;
			return '-';
		}
	}

	if (isdigit(c))   // collect integer part
		while (isdigit(s[++i] = c = buf[bufp++]))
			;
	
	if (c == '.')	// collect fraction part
		while (isdigit(s[++i] = c = buf[bufp++]))
			;
	
	s[i] = '\0';
	if (c != EOF)
		bufp--;

	return NUMBER;
}

int get_line()
{
    int c,i;
    for ( i = 0; i<(BUFSIZE-1) && (c = getchar()) !=EOF && c != '\n'; ++i)
		buf[i] = c;
	if ( c == EOF)
		return EOF;
	if ( c == '\n') {
		buf[i] = c;
		++i;
	}
	buf[i] = '\0';
	return i;

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
