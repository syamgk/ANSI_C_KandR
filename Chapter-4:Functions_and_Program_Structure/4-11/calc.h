#include <math.h>
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION 'f'
#define VARIABLE 'A' /* signal that a variable found*/

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);
