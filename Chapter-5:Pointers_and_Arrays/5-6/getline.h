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
