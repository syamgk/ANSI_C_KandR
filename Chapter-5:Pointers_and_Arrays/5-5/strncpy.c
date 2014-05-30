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
	printf("Before:>%s\n",a);
	str_ncpy(a,"hi",5); // try a number greater than the len(array)
	printf("\nAfter:>%s\n",a);
}
