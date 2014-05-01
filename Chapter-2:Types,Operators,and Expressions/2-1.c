#include<stdio.h>
#include<float.h>
#include<limits.h>
// prints ranges of char,short,int and long variables
main()
{
	printf("\n----Ranges----\n\nSigned:-\n---------");
	printf("\nchar  | min:%15d\tmax:%15d",CHAR_MIN,CHAR_MAX);
	printf("\nshort | min:%15d\tmax:%15d",SHRT_MIN,SHRT_MAX);
	printf("\nint   | min:%15d\tmax:%15d",INT_MIN,INT_MAX);
	printf("\nlong  | min:%15ld\tmax:%15ld\n",LONG_MIN,LONG_MAX);
	printf("\n\nUnsigned:-\n---------");
	printf("\nchar  | min:xxxxx\tmax:%15d",UCHAR_MAX);
	printf("\nshort | min:xxxxx\tmax:%15d",USHRT_MAX);
	printf("\nint   | min:xxxxx\tmax:%15u",UINT_MAX);
	printf("\nlong  | min:xxxxx\tmax:%15lu\n",ULONG_MAX);
	
}
