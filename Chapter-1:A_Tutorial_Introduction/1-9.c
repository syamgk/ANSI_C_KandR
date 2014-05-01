#include<stdio.h>
/* replaceing each string of one or more blanks by a single blank of input and display it*/
main()
{
	int a,prev_a = 0 ;
	while ( (a = getchar()) != EOF ) {
		if ( a != " ") {
			putchar(a);
			prev_a = a;
		}
		else if( a == " "){
			if ( prev_a == " ")
				
			printf("spacereached");
			prev_a = a; 
		}
	}
}
