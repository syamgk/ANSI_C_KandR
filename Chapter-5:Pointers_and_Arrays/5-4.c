#include<stdio.h>
#include<string.h>

//check if string t occurs at end of s
int strend(char *s,char *t)
{
	int i;
	s += strlen(s)- strlen(t);
	printf(">>%c<<\n",*s);
	for(i = 0; i <strlen(t);i++) {
		if (*s == *t) {
			printf("s=%c::t=%c\n",*s,*t);	
			s++;
			t++;
		}
		else
			return 0;
	}
	return 1;
}
//	printf(">>%c<<\n",*s);
//	printf(">>%c<<\n",*t);
main()
{
	char s[] = "hello_world";
	char t[] = "world";
	int a = strend(s,t);
	printf(">>a = %d<<\n",a);
}
