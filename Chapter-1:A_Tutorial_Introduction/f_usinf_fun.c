#include<stdio.h>

  /* print Fahrenheit-Celsius table
      for fahr = 0, 20, ..., 300 */
int ftoC( int fahr);
main()
{ 
    int fahr;
    int lower, upper, step;
    lower = 0;    /* lower limit of temperature scale */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3d\t%6d\n", fahr, ftoC(fahr));
        fahr = fahr + step;
    }
}
int ftoC ( int F) 
{
	int c;
	c = 5 * (F-32) / 9;
	return c;
}

