#include<stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[],int maxline);
void cpy(char to[], char from[]);

/*print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0 ) 
		if (len > max)  {  /* checking longest */
			max = len;
			cpy(longest, line);
		}
	if (max > 0 ){
		printf("longest line is;\n%s",longest); 
		printf("Line LENGTH :%d\n",max);
	}
	else 
		printf("invalid Input");
	return 0;
}

/*getline: read a line into s, return length */
int get_line(char s[], int limt)
{
	int c,i;
	for ( i = 0; i<(limt-1) && (c = getchar()) !=EOF && c != '\n'; ++i)
		s[i] = c;
	if ( c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/* copy: copy 'from' into 'to' ;assume to is big enough */
void cpy(char to[],char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

