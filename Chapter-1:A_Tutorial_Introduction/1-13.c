#include<stdio.h>

main()
{ 
	int ch, liw[100], i;
	int n = 0 ;
	int bigwords = 0;
	printf("Counting lengths upto 99 remaining as other\n");
	for (i =0; i < 100 ; ++i)
		liw[i] = 0;
	
	printf("_____________________________________________");
	while ( (ch = getchar()) != EOF) {
		if (ch == ' '||ch == '\t'||ch == '\n') {
			if (n < 100)
				++liw[n];
			else
				++bigwords;
			n = 0;
		}
		else
			++n;
	}
	for (i=0; i<100;i++) {
		printf("\n%3d::",i);
		while ( liw[i] != 0) {
			printf("#");
			--liw[i];
		}
	}
	printf("\nbigwords::%d\n",bigwords);
}
