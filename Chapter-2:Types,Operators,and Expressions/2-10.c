#include<stdio.h>

int lower(int c)
{
	return (c>= 'A' && c <= 'Z')? (c + 'a'-'A'): c;
} 
main()
{
	printf("Enter ';' to quit");
	char c;
	while( (c = getchar()) != ';') {
		printf("%c",lower(c));
	}
}

