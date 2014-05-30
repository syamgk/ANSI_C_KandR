#include<string.h>
#include"getlinea.h"
#define MAXLEN 1000 	/* max length of any input line */
int getlinea(char*, int); // from getlinea.h
//char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines,char *linebuff)
{
	int len, nlines;
	char *p = linebuff;
	char line[MAXLEN];

	nlines = 0;
	while(( len = getlinea(line, MAXLEN)) > 0)
		if( nlines >= maxlines || (p += len ) > &linebuff[100000] )
			return -1;
		else {
			line[len-1] = '\0'; /* delete newlines */
			strcpy(p-len, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines*/
void writelines(char *lineptr[], int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) /* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

