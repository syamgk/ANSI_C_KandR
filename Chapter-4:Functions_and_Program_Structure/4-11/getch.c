#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// gets a (possible pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
//pushes a character back on the input
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters");
	else
		buf[bufp++] = c;
}
*/
