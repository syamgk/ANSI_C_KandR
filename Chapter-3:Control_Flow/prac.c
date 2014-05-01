#include<stdio.h>

main()
{
	int i=0,j=1,k=0;
	for(i=0,k=1; k<5 ; i++,k++){
		printf("i%d__k%d\n",++i,k);
	}
	printf("===\n");
}
