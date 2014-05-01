#include<stdio.h>

main()
{
	int c, a[127];
	int i, j;
	for (i = 0; i < 127; ++i) 
		a[i] = 0;
	while ((c = getchar()) != EOF) {
		for (i = 0; i < 127; ++i) {
			if ( i == c)
				++a[i];
		}
	}
	for (i = 0; i < 127; ++i) {
		if ( a[i] > 0) {
			putchar(i);
			printf("::");
			while ( a[i] > 0) {
				printf("#");
				--a[i];
			}
			printf("\n");
		}
	}
}
