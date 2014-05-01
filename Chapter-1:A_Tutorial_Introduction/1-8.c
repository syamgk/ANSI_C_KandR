#include <stdio.h>
/* count blanks,tabs and newlines in input */
main()
{
int c, nl, nt, nb;
nl = nt = nb = 0;
while ((c = getchar()) != EOF)
	if (c == '\n')
		++nl;
	else if (c == '\t')
		++nt;
	else if (c == ' ')
		++nb;	
printf("NewLines :%d\n", nl);
printf("Tabs :%d\n", nt);
printf("Blanks :%d\n", nb);
}
