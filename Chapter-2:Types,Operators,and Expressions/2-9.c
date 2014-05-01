/*	x &= (x-1) ; 
	let x = 0xf;      whose binary is '1111'
	  => (x-1) = 0xe; whose binary is '1110'

	    ==> x &= (x-1) <=> [1111] &= [1110]
			      ===>[1110] ---> the last bit in 0xf get deleted!
*/
#include<stdio.h>

/* bitcount :counts 1 bits in x */
int bitcount(unsigned x)
{
	int b;
	for(b = 0; x != 0; x &= (x-1))
		b++;
	return b;
}

main()
{
	int a = 0xff;
	printf("%d 1'bits in %d\n", bitcount(a),a);
}
