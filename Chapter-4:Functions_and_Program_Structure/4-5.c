#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION 'f'
#define MAXVAL 100	// maximum depth of val stack
#define BUFSIZE 100

int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack
char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void function(char[]);

main()
{
	int i;
	int type;
	double op2;
	char s[MAXOP];

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
			case FUNCTION:
				function(s);
				break;
			case '\n':               // print and pop()
				printf("\t%.8g\n", pop());
				break;
			case 'C':
				sp = 0;
				break;
			case 'P':                // print top element
				printf("top_element:%g\n",val[sp++]);
				break;
			case 'S':  // swap last two on stack
				op2 = val[sp];
				val[sp] = val[sp-1];
				val[sp-1] = op2;
				printf("swapped");
				break;
			case '|':  // prints array val[];
				for( i = 0; val[i] != 0; i++)
					printf("%g, ",val[i]);
				printf("\n");
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
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
	if (islower(c)) {
		while (islower(c = getch())) 
			s[++i] = c;
		s[++i] = '\0';
		if(c != EOF)
			ungetch(c);
		return FUNCTION;
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
	
