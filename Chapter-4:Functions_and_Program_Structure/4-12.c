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
		

