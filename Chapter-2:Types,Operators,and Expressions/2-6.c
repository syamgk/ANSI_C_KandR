#include<stdio.h>

unsigned setbits(unsigned x, int p,int n,unsigned y)
{
	return x & ~(~(~ 0 << n) << (p+1 - n)) |
		( y & ~(~ 0 << n)) << (p+1 - n);
}

main()
{
	unsigned a = 0xf, b = 0;
	int i;
	int n = 2;
	for (i = 1; i < 5; ++i){ // moving position
		int p = i;
		printf("%d",~(~(~ 0 << n) << (p+1 - n)));
		printf("\n%d",~(~ 0 << n)) ;
		printf("a = %d; b = %d, n = %d;"
			" p(position) = %d",a,b,n,p);
		printf("\n =>%d\n\n",setbits(a,p,n,b));
	}
}
