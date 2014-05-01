#include<stdio.h>
/* draws a histogram of char and frequency */
main()
{
	int a[127], i,j;
	int c;
	for (i = 0; i < 127; ++i)
		a[i] = 0;
	while ((c = getchar()) != EOF)
		for (i = 0; i < 127; ++i) {
			if (c == i) {
				++a[i];
			}
		}
	for (i = 0; i< 127; ++i) {
			if ( a[i] != 0) {
				putchar(i);
				printf("::");
				for ( j =a[i] ; j>0; --j)
					printf("#");
				printf("\n");
		}
	}
}
