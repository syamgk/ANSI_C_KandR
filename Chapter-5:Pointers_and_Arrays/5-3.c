#include<stdio.h>
//concatenate two strings
void str_cat(char *p, char *q)
{
	while(*p != '\0')
		p++;
	while((*p++ = *q++) != '\0')
		;
}

main()
{
	char a[] = "hello_";
	char b[] = "world";
	str_cat(a,b);
	printf("%s\n",a);
}
