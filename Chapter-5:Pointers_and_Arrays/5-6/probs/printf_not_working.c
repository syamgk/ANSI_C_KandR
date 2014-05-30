#include<stdio.h>
#include<string.h>

void reverse(char* s)
{
	char temp;
	char* end = s;
	printf("SA");
	while(end != '\0')
		end++;
	printf(">>%d<<",*end);
	for(; s < end;s++, end-- ) {
		temp = *end;
		*end = *s;
		*s = temp;
	}
}

/*	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}*/

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
	printf("%d\n",*s);
	reverse(t);
}
		

main()
{
	int a = -199;
	char s[16];
	itoa(a, s);
	printf("\n%s\n",s);
}
