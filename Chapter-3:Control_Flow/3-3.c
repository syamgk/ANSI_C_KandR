#include<stdio.h>
#define LIMIT 100

void expand(char s1[], char s2[])
{
	int i, j, k = 0;
	for(i = 0;s1[i] != '\0'; i++) {
		if(i != 0 && s1[i] == '-' && s1[i-1] < s1[i+1] )
			for(j = s1[i-1]; j+1 < s1[i+1];)
				s2[k++] = ++j;
		else
			s2[k++] = s1[i];
	}
	s2[k] = '\0';
}

main()
{
	char a[] = "-a-c-f-i !-$ 0-9 \np-t";
	char b[LIMIT];
	expand(a,b);
	printf("Test::\ns1\n%s\n========\ns2\n%s\n", a, b);
}			
