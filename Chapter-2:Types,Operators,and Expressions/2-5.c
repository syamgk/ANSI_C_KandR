#include<stdio.h>


/*check character presence and position*/
int char_pos(char s[], int c)
{
	int i, j, pos = -1;

	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] == c) {
			pos = i;
			break;
		}
	return pos;
}

// print fist occurence of any char(s2) in s1
void any(char s1[],char s2[])
{
	int i, k;

	for( i = k =0; s1[i] != '\0'; i++) {
		if(char_pos(s2, s1[i]) != -1) {
			printf("%d",i);
			break;
		}
	}
	if(s1[i] == '\0')
		printf("-1");
}
//test case:
main()
{
	char a[] = "test !case 1";
	char b[] = "!as";
	any(a,b);
}
