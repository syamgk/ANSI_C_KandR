#include<stdio.h>
#include<ctype.h>
#define MAXLINE 1000
int getlinea(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exp = 0, es;/*es - sign of exponent*/
	for (i = 0; isspace(s[i]); i++) /*skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
// exponent part 
	if (s[i] == 'e' || s[i] == 'E') {    
		es = (s[++i] == '-')? -1 : 1;
		for(exp = 0; isdigit(s[i]); i++) {
			exp = 10 * exp + (s[i]-'0');
		}
		if (es == -1)
			while (exp-- > 0)
				val /= 10;
		else 
			while (exp-- > 0)
				val *= 10;
	}
	return val;
}
main()
{
	double  sum, atof(char []);
	char line[MAXLINE];
	int getlinea(char line[], int max);

	sum = 0;
	while (getlinea(line, MAXLINE) >0)
		printf("\t%g\n",atof(line));
	return 0;
}
