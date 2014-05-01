#include<stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[],int maxline);
void reverse(char s[]);

/*remove tabs and trailing blanks and delete blank lines  */
main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0 ) {
		printf("\n%s",line);
		reverse(line); 
		printf("\n%s",line);
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

void reverse(char s[])
{
	int i, j;
	char temp;
	for (i = 0; s[i] != '\0'; ++i);

	--i;
	j = 0;
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}
