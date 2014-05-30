static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	if(month < 1 || month > 12)
		return -1;	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	if(day < 1 || day > *(*(daytab+leap)+month))
		return -1;
	for (i = 1; i < month; i++)
		day += *(*(daytab+leap)+i);
	return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if( year < 1) {
		*pmonth = -1;
		*pday = -1;
		return -1;
	}
	if( yearday < 1 || yearday > (365+leap)) {
		*pmonth = -1;
		*pday = -1;
		return -1;
	}

	for (i = 1; yearday > *(*(daytab+leap)+i); i++)
		yearday -= *(*(daytab+leap)+i);
	*pmonth = i;
	*pday = yearday;
}
//for testing purpose
main()
{
	int a;
	int b;	
	month_day(1990,270,&a,&b);
	printf("month:%d\nday:%d\n",a,b);
	month_day(1991,366,&a,&b);
	printf("month:%d\nday:%d\n",a,b);
	month_day(1992,366,&a,&b);
	printf("month:%d\nday:%d\n",a,b);
	month_day(1993,366,&a,&b);
	printf("month:%d\nday:%d\n",a,b);
	printf("%d\n",day_of_year(1990,12,31));
	printf("%d\n",day_of_year(1991,12,31));
	printf("%d\n",day_of_year(1992,12,31));
	printf("%d\n",day_of_year(1993,12,31));
}

