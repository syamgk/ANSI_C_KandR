#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;
	while(isspace(c = getch()))	/*skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);  /* it's not a number */
		return 0;
	}
	sign = (c == '-')? -1: 1;
	if (c =='+' || c == '-')
		if (!isdigit(c = getch())){
			ungetch(c);
			return sign;
		}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn +(c -'0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

main()
{
	int g,a = 999;
	while((g =getint(&a)) != 0) {
		printf("\n--------> %d <----------\n",g);
		printf("\n-------->a=%d<----------\n",a);
	}
}
