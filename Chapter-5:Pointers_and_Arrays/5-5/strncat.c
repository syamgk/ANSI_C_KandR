#include<stdio.h>

void str_ncat(char *dest, char *ct, int n)
{
	int i;
//	printf("%c\n",*dest);
	while(*dest)
		dest++;
//	printf("last_char: %c\n",*(dest-1));
	for(i=0; i< n; i++)
		*dest++ = *(ct++);
	*dest = '\0';
}

main()
{
	char dst[20] = "hello_";
	printf("before: %s\n",dst);
	str_ncat(dst,"world",5);
	printf("after: %s\n",dst);
}

