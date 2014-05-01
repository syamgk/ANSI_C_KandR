#include<stdio.h>
unsigned rightrot(unsigned x, int n)
{
	int rtol;
	while( n-- > 0) {
		rtol = (x & 1) << (32 - 1);
		x = x >> 1 | rtol;
	}
	return x;
}

main()
{
	unsigned a = 0xff;
	int n = 2;
	printf("a = %d, n = %d" ,a, n);
	printf("\n =>%d\n\n",rightrot(a, n));
        
}


