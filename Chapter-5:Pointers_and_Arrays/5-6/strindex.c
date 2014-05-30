#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
char pattern[] = "ould";

/* getlinea: get line into s, return length */
int getlinea(char* s, int lim)
{
    int c;
	char* i = s;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char* s, char* t)
{	
	char* st = s;
	char *p,*q;
	int index = -1;
	for(;*s != '\0';s++) {
		for(p = s, q = t;*q != '\0' && *p == *q; p++,q++)
			;
		if( *q =='\0')
			index = (s -st );
		continue;
	}
	return index;
}

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;
    while (getlinea(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s---on above line found @%d\n", line, strindex(line, pattern));
            found++;
        }
    printf("##search pattern '%s' found on %d lines\n",pattern, found);
}
