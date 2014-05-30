#include<stdio.h>

void str_ncmp(char *cs, char *ct, int n)
{
	int i;
	for(i=0; i<n; i++) {
		if(*cs == *ct)
			printf("%c:=:%c\n",*cs++,*ct++);
		else
			printf("not matching\n");
	}
}

main()
{
	char s[]="hello";
	char t[]="hellw";
	str_ncmp(s,t,5);
}

