#include<stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[],int maxline);

/*remove tabs and trailing blanks and delete blank lines  */
main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0 ) 
		if (len > 1)  {  
			printf("%s",line); 
		}
	return 0;
}

/*getline: read a line into s, return length */
int get_line(char s[], int limt)
{
	int c,i;
	for ( i = 0; i<(limt-1) && (c = getchar()) !=EOF && c != '\n'; ++i) {
		if ( (c == s[i-1]) && ( c == ' '|| c == '\t')) {
			--i;
			continue;
		}
		s[i] = c;
	}
	if ( c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
