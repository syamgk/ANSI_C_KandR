#include<stdio.h>
#include<string.h>

//check if string t occurs at end of s
int strend(char *s,char *t)
{
	int i;
	int len_t = strlen(t);
	s += strlen(s)-len_t;
	printf(">>%c<<\n",*s);
	for(i = 0; i < len_t; i++) {
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

main()
{
	char s[] = "hello_world";
	char t[] = "_world";
	int a = strend(s,t);
	printf(">>a = %d<<\n",a);
	a = strend("hello_moto"," mot ");
	printf(">>a = %d<<\n",a);
	a = strend("GNU/Linux","nua");
	a = strend("is"," fine");
	printf(">>a = %d<<\n",a);
}
