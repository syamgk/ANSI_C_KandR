#include<stdio.h>
#define TABSTOP 8
/*replace strings of blanks with tabs and blanks */
main()
{
	int c;
    int pos,nb, nt;
	nb = 0;  // no of blanks required
	nt = 0;  // no of tabs required
	for(pos = 0; (c = getchar()) != EOF; pos++) {
		if( c == ' ') {
			if( pos % TABSTOP != 0)
				++nb;
			else {
				nb = 0;
				++nt;
			}
		} else {
			for ( ; nt > 0; --nt)
				putchar('\t');
			if(c =='\t')
				nb = 0;
			else
				for( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if( c == '\n')
				pos = 0;
			else if( c == '\t')
				pos = pos +( TABSTOP - (pos -1) % TABSTOP) - 1;
		}
	}
} 
