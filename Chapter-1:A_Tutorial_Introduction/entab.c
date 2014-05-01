#include<stdio.h>
#define TABSTOP 8
/*entab the spaces with tab and space*/
main()
{
    int k,c;
    int i,d;
    int prev;
    int space_count = 0;
        while ((c = getchar()) != EOF ) {
            if (c ==' ') {
                prev = c;
                ++space_count;
            }
            else if ( prev==' '&& c != ' '){
              //  printf("%d",space_count);
                k = space_count % TABSTOP;
                d = space_count / TABSTOP;
                for( i = 0; i < d; ++i){
              //      printf("<t>");
                    putchar('\t');
                    putchar(' ');
                }
                for ( i = 0; i < k; ++i)
                    putchar(' ');
                    prev = c;
                    putchar(c);
                    space_count = 0;
            }
            else
                putchar(c);
        }
}
