#include <stdio.h>

int get_week_day(long int, int, int);    // day month year

void get_date(int, int&, int&, int&);  // days day month year


int main()
{

    char week[7][23] = {
                                    "Понедельник",
                                    "Вторник",
                                    "Среда",
                                    "Четверг",
                                    "Пятница",
                                    "Суббота",
                                    "Воскресенье"
                                    };

    int day, month, year;

    int days = 365;

    get_date(65884 , day, month, year);
    //79538 -> 7 10 2017
    //73770 -> 22 12 2001
    //65884 -> 19 5 1980

    //printf("%d\n\n", get_week_day(19, 5, 1980));

    printf("%d - %d - %d", day, month, year);



    return 0;
}



int get_week_day(long int day, int month, int year)
{
    const char monthes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long int counter = 1;

    for (int i= 1800; i < year; i++)
        if (i%4==0 && (i%100!=0 || i%400==0)) counter += 366;
        else counter += 365;

    for (int i = 0; i < month-1; i++)
        counter += monthes[i];

    if ( (month > 2) && (year%4==0 && (year%100!=0 || year%400==0)) ) counter++;

    counter += day;
    counter %= 7;

    return counter;
}


void get_date(int days, int& day, int& month, int& year)
{
    const char monthes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    year = 1800;

    while (days > 365)
    {
        if (year%4==0 && (year%100!=0 || year%400==0)) days -= 366;
        else days -= 365;
        year++;
    }

    for  (month = 1; days > monthes[month-1]; days -= monthes[month-1], month++);

    if ( month > 2 && (year%4==0 && (year%100!=0 || year%400==0)) ) days--;

    day = days;

}
