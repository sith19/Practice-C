#include <stdio.h>
day_of_year(int year, int month, int day);
month_day(int year, int yearday, int *pmonth, int *pday);
/*void main()
{
    char ** black[55];
    char * gun[] = {"Jamica", "America", "yellow", "red", "black"};
    black[1] = gun;
    printf("%p\n", black[1]);
    printf("%s\n", black[1][1]);
    printf("%d\n", day_of_year(2024, 3, 1));  // Output: 61
    printf("%d\n", day_of_year(2023, 3, 1));

}*/
static char *daytab[] = {
    (char[]){0,31,28,31,30,31,31,31,30,31,30,31},
    (char[]){ 0,31,29,31,30,31,30,31,31,30,31,30,31 }};

day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 ==0 && year % 100 != 0) || year % 400 == 0;
    for(i = 1; i <= month; i++)
    {
        day +=daytab[leap][i];
    }
    return day;
}
month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year % 4 ==0 && year % 100 != 0) || year % 400 == 0;
    for(i = 1; i <yearday; i++)
    {
        yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;

    }

}
