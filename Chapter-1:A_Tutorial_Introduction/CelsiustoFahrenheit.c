#include<stdio.h>
  /* print Fahrenheit-Celsius table
      for fahr = 0, 20, ..., 300 */
main()
{   
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;    /* lower limit of temperature scale */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */
    printf("%10s","Celsius to Fahrenheit:\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius,fahr);
        celsius = celsius + step;
    }
}

