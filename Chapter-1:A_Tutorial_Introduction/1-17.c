#include<stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[],int maxline);

/*print lines greater than 80 characters */
main()
{
	int len;
	int min;
	char line[MAXLINE];
	char longest[MAXLINE];

	min = 80;
	printf("The lines longer than 80 characters are ;\n");
	while ((len = get_line(line, MAXLINE)) > 0 ) 
		if (len > min)  {  
			printf("%s",line); 
		}
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
