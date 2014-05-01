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


void itob(unsigned n, char s[], int b)
{
	int c, i = 0;
//	char sign;
//	sign  = (n < 0)? '-': '+';
	do {
		c = n % b;
		n = n / b;
		if(c <= 9)
			c = '0' + c;
		else if(c > 9)
			c = 'A' + (c -10);
		s[i++] = c;
	} while(n != 0);
//	s[i++] = sign;
	s[i] = '\0';
	reverse(s);
}		


main()
{
	char s[24];
	itob(255, s, 2);
	printf("%s\n",s);
	itob(255, s, 16);
	printf("%s\n",s);
	itob(255, s, 7);
	printf("%s\n",s);
}
