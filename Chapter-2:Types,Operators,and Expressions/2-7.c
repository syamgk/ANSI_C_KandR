#include<stdio.h>

unsigned invert(unsigned x, int p, int n)
{
	return ~(x & ~(~0<<n) << (p+1-n)) &
		~(~(~0 << n) << (p+1-n));
}

main()
{
	unsigned a = 0xff;
	int i;
	int n = 2;
	for (i = 1; i < 5; ++i){ // moving position
		int p = i;
		printf("a = %d, n = %d;"
			" p(position) = %d",a,n,p);
		printf("\n =>%d\n\n",invert(a,p,n));
        }
}


