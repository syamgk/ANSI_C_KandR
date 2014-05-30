#include<stdio.h>
#include<ctype.h>
/* atoi: convert a to integer */
int atoi(char* s)
{
	int n, sign;
	for(; *s == ' ';s++)
		;
	sign = (*s == '-')? -1: 1;
	if(*s == '+' || *s == '-') //skip sign
		s++;
	for(n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return sign * n;
}

main()
{
	char a[] = "456";
	printf("%d\n",atoi(a));	
	char b[] = "-456";
	printf("%d\n",atoi(b));
}
