#include<stdio.h>

//swap varaibles in an array
void swp(char str[], int i, int j)
{
	int temp;
	temp = *(str+i);
	*(str+i) = *(str+j);
	*(str+j) = temp;
}

//reverses a string array
void reverse(char* s)
{
	static int p = 0;
	if( p != (strlen(s)/2)){
		swp(s, p, strlen(s)-(p+1));
		p++;
		reverse(s);
	}
	
}
main()
{ 
	char a[] = "123456";
	printf("Before:\n");
	printf("%s\n",a);
	reverse(a);
	printf("\nAfter:\n");
	printf("%s\n",a);
}

