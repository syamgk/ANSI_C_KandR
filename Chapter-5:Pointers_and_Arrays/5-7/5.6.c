#include<stdio.h>
#include<string.h>

#define MAXLINES 5000 /* max lines to be stored */

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char * linebuff);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// sort input lines
main()
{
	int nlines; 
	char linebuff[100000];

	if((nlines = readlines(lineptr, MAXLINES,linebuff)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

