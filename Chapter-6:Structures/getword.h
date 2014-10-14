#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define BUFSIZE 100
int buf[BUFSIZE];	//buffer for ungetch
int bufp=0;			//buffer pointer
// gets a (possible pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//pushes a character back on the input
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters");
	else
		buf[bufp++] = c;
}


//getword: get next word or character from input
int getword(char *word, int lim)
{
  int c, d, comment(void), getch(void);
  void ungetch(int);
  char *w = word;
  while(isblank(c = getch()))
    ;
  if(c !=EOF)
    *w++ = c;
  if(isalpha(c) || c == '-' || c == '#'){
    for(; --lim > 0; w++)
      if(!isalnum(*w = getch()) && *w != '-') {
	    ungetch(*w);
	    break;
      }
  } else if(c == '\'' || c == '"') {
    for( ; --lim > 0; w++)
      if((*w = getch()) == '\\')
	    *++w = getch();
	else if(*w == c) {
	    w++;
	    break;
	  } else if (*w == EOF)
	    break;
  } else if (c == '/')
	  if((d = getch()) == '*')
	    c = comment();
	  else
	    ungetch(d);
  *w = '\0';
  return c;
}
 
//comment: skip over comment and return a character
int comment()
{
    int c;
    while((c = getch()) != EOF)
      if(c == '*')
	    if((c = getch()) == '/')
	      break;
	    else
	      ungetch(c);
    return c;
}
