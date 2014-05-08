#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
char pattern[] = "ould";


/* getline: get line into s, return length */
int getlinea(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k, index = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;
        continue;
    }
    return index;
}

/* pattern to search for */
/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;
    while (getlinea(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s:\t : %d", line, strindex(line, pattern));
            found++;
        }
    printf("%d", found);
}
