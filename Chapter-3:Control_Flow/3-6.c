#include<stdio.h>
#include<string.h>

//reverses a string
void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

//converts unsigned int n into base b in string
void itob(unsigned n, char s[], int b , int w)
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
	while(i < w) 
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}		

//test for unsigned convertion itob
main()
{
	char s[24];
	itob(255, s, 2, 3);
	printf("%s\n",s ,8);
	itob(255, s, 16 ,8);
	printf("%s\n",s);
	itob(255, s, 7 ,8);
	printf("%s\n",s);
}
