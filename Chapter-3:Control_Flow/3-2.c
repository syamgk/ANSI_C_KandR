#include<stdio.h>
#define LIMIT 100
void reverse_escape(char t[], char s[]);
void escape(char s[], char t[])
{
	int i = 0, k = 0;
	for(; s[i] != '\0'; i++, k++) {
		switch(s[i]){
			case '\n':
				t[k++] = '\\';
				t[k] = 'n';
				break;
			case '\t':
				t[k++] = '\\';
				t[k] = 't';
				break;
			default:
				t[k] = s[i];
				break;
		}
	}
	t[k]='\0';
}
	
main()
{
	char a[] = "hello\n\t world\t Iam\t___> here";
	char b[LIMIT];
	char c[LIMIT];
	escape(a,b);
	printf("a::%s\nb::%s\n",a,b);
	reverse_escape(b,c);
	if(a == c)
		printf("a and c are equal");
	printf("b::%s\nc::%s\n",b,c);
}

void reverse_escape(char t[], char s[])
{
	int i = 0,k = 0;
	for(;t[i] != '\0'; i++, k++) {
		if(t[i] == '\\')
			switch(t[++i]) {
				case 'n':
					s[k] = '\n';
					break;
				case 't':
					s[k] = '\t'; 
					break;
				default:
					printf("other than\\n & \\t");
					break;
			}
		else
			s[k] = t[i];
	}
	s[k] = '\0';
}
