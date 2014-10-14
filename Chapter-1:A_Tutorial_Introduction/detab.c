#include<stdio.h>
#define TABSTOP 4

main()
{
    int i,c;
	int ts;
	int pos = 1;
        while ((c = getchar()) != EOF ) {
            if ( c == '\t') {
				ts = TABSTOP - (pos -1) % TABSTOP;
                for (i = 0; i < ts; ++i) {
                    putchar(32);
					pos++;
				}
            } else if( c == '\n') {
				putchar(c);
				pos = 1;
			}
            else {
                putchar(c);
				pos++;
			}
        }
}
