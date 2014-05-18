#include<stdio.h>
#include<string.h>

//swap varaibles in an array
void swp(char str[], int i, int j)
{
	int temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

//reverses a string array
void reverse(char s[])
{
	static int p = 0;
	if( p != (strlen(s)/2)){
		swp(s, p, strlen(s)-(p+1));
		p++;
		reverse(s);
	}
	
}
//absolute value of x
int abs( int x)
{
	return (x < 0) ? x : -x;
}
//convert int to corresponding asci in char[] 
void itoa(int n, char s[])
{
	static int sign[] ={ 1};
	static int i = 0;
	if( i == 0 && n < 0)
		sign[0] = -1;
	s[i++] = abs(n % 10) + '0';
	n = n / 10;
	if( n != 0)
		itoa(n,s);
	else {
		if(sign[0] == -1)
			s[i++ ] = '-';
		s[i] = '\0';
		reverse(s);
	}
}
		

main()
{
	int a = -1234;
	char s[16];
	itoa(a, s);
//	reverse(s);
	printf("\n%s\n",s);
}
