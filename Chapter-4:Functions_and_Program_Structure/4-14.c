#include<stdio.h>

#define swap(t, x, y)   t temp;\
						temp = x;\
						x = y;\
						y = temp; 

main()
{
	int a =10, b =555;
	swap(int, a, b)
	printf("a =%d:\t:b =%d\n",a,b);
}

