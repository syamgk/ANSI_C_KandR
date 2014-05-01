#include<stdio.h>

#define limt 100

int htoi(char s[])
{
	int result = 0;
	int i = 0, dig;

	if(s[i] == '0')  //skip optional '0x' or '0X' 
		++i;
	if(s[i] == 'x' || s[i] == 'X')
		++i;
	
	for(; i < limt ; ++i) {
		if(47 < s[i] && s[i] < 58)  // 0 -9
			dig = s[i] -'0';
		else if(96 < s[i] && s[i] < 103) // a - f
			dig = s[i] - 'a' + 10;
		else if(64 < s[i] && s[i] < 71) // A - F
			dig = s[i] - 'A' + 10;
		else
			break;
		result = 16 * result + dig;
	}
	return result;
}

/* for testing the above function
main()
{
	printf("0XABC::%d",htoi("0XABC"));
	printf("\n7::%d",htoi("7"));
	printf("\nF::%d",htoi("F"));
	printf("\n255::%d",htoi("255"));
	printf("\nDEFF::%d",htoi("DEFF"));
	printf("\n");
}
*/
