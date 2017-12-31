#include <stdio.h>
#include "conio.h"

bool YesNo()
{
    while (1)
        switch (getch())
        {
            case 'y': printf("y\n"); return 1;
            case 'n': printf("n\n"); return 0;
        }
}

void time_to_sec()
{
    int h, m, s;
    char ch;
    do
    {
        printf("Введите время в формате: [h:m:s] ->\t");
        scanf("%d:%d:%d", &h, &m, &s);

        if (h <= 23  && h >= 0 && m <= 59 && m >= 0 && s <= 59 && s >= 0)
            printf("\nОт 00:00:00 до %d:%d:%d ровно %d сек.\n", h, m, s, h*3600+m*60+s);
        else printf("!!!Неверный временной формат!!!");

        printf("\nХотите повторить? y/n\t");

    } while (YesNo());

}

void check_day()
{
    char ch;
    do
    {
        printf("Введите номер дня недели: ");
        int day;
        scanf("%d", &day);

        switch (day)
        {
            case 1: printf("\nНомер соответсвует понедельнику\n\n");
                break;
            case 2: printf("\nНомер соответсвует вторнику\n\n");
                break;
            case 3: printf("\nНомер соответсвует среде\n\n");
                break;
            case 4: printf("\nНомер соответсвует четвергу\n\n");
                break;
            case 5: printf("\nНомер соответсвует пятнице\n\n");
                break;
            case 6: printf("\nНомер соответсвует субботе\n\n");
                break;
            case 7: printf("\nНомер соответсвует воскресенье\n\n");
                break;
            default: printf("\nОшибка!!! Номер не соответствует ни одному дню недели!!!\n\n");
        }

        printf("Хотите повторить? y/n\t");

    } while (YesNo());
}


int main()
{
    time_to_sec();

    check_day();

    return 0;
}
