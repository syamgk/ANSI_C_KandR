#include<stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid = 0;
	low = 0;
	high = n - 1;
	while (low < high && x != v[mid]) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	mid = (x == v[mid + 1])? mid = mid+1 : mid;  
	if (x == v[mid])
		return mid;
	else 
		return -1;		/* no match */
}


main()
{
	int a[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[10] ;
	int n = 0 ;
	while(n < 10 ){
		printf("a[%d] = %d :: %d on binsearch found@%d\n",n,a[n],a[n],binsearch(a[n],a,10));
		++n;
	}
	printf("************\n");
}

