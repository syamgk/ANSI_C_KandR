#include<stdio.h>
#include<string.h>

void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int abs( int x)
{
	return (x < 0) ? x : -x;
}

void itoa(int n, char s[])
{
	int sign;
	int i = 0;
	sign = n;
	do {
		s[i++] = abs(n % 10) + '0';
		n = n / 10;
	} while( n != n / 10);
	if( sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
		

main()
{
	int a = -199;
	char s[16];
	itoa(a, s);
	printf("\n%s\n",s);
}
