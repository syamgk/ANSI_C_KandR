#include<stdio.h>

enum boolean {NO ,YES};

/*check character presence */
int check_char(char s[], int c)
{
	int i, j, decision = NO;

	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] == c)
			decision = YES;
	return decision;
}

//program to squeeze strings!
void squeeze(char s1[],char s2[])
{
	int i, k;

	for( i = k =0; s1[i] != '\0'; i++) {
		if(check_char(s2, s1[i])) { // if present we need to skip that charecter
// 			printf("reached1");
		}
		else 
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}
//test case:
main()
{
	char a[] = "p!e@ac#e_l!_o#v!e_@j_o!y";
	char b[] = "!@#_";
	printf("Before:\na[]%s\nb[]%s\n",a,b);
	squeeze(a,b);
	printf("After:\na[]%s\nb[]%s\n",a,b);
}

