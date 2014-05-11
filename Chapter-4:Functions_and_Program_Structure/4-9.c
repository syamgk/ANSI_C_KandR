#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include<string.h> 	// for strlen()

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION 'f'
#define VARIABLE 'A' /* signal that a variable found*/
#define MAXVAL 100	// maximum depth of val stack
#define BUFSIZE 100

int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack
int buf[BUFSIZE];	// buffer for ungetch ::changed to int for including (EOF = -1)
int bufp = 0;		// next free position in buf

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void function(char[]);
void ungets(char[]);

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

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	i = 0;
	if (islower(c) && c != 'v') {
		while (islower(c = getch())) 
			s[++i] = c;
		s[++i] = '\0';
		if(c != EOF)
			ungetch(c);  
		return FUNCTION;
	}
	if (isupper(c) || c == 'v') {
		if (isupper(c))
			s[0] = c - 'A';
		return VARIABLE;
	}
	if (!isdigit(c) && c != '.' && c != '-') //not a number
		return c;
	if (s[0] == '-') {
		if (isdigit(c = getch()) || c =='.')
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}

	if (isdigit(c))   // collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	
	if (c == '.')	// collect fraction part
		while (isdigit(s[++i] = c = getch()))
			;
	
	s[i] = '\0';
	
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

// gets a (possible pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//pushes a character back on the input
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters");
	else
		buf[bufp++] = c;
}
/* ungets has indirect link with buf and bufp via ungetch() */
void ungets(char s[])
{
	int len = strlen(s);
	while( len > 0)
		ungetch(s[--len]);
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
