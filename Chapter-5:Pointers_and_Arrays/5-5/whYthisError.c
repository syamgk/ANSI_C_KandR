#include<stdio.h>

void str_ncpy(char *dest, char *c, int n)
{
	int i;
	for( i = 0; i<n; i++)
		*dest++ = *c++;
	dest ='\0';
}
main()
{
	char a[9];
	printf("B:%s\n",a);
	str_ncpy(a,"hello_world",15);
	printf("\nA:%s\n",a);
}
