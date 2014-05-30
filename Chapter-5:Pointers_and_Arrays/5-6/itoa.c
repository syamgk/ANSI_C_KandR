#include<stdio.h>
#include<string.h>
//reverses the strings
void reverse(char* s)
{
	char temp;
	char* end = s;
	while(*end != '\0')
		end++;
	end--;
	for(; s < end;s++, end-- ) {
		temp = *end;
		*end = *s;
		*s = temp;
	}
}
//absolute value of a number
int abs( int x)
{
	return (x < 0) ? x : -x;
}
//int to array
void itoa(int n, char* s)
{
	int sign;
	char* t = s;
	sign = n;
	do {
		*s++ = abs(n % 10) + '0';
		n = n / 10;
	} while( n != n / 10);
	if( sign < 0)
		*s++ = '-';
	*s = '\0';
	printf("%d",*s);
	reverse(t); // t is the starting memory location of string
}
		

main()
{
	int a = -199;
	char s[16];
	itoa(a, s);
	printf("\n%s\n",s);
}
