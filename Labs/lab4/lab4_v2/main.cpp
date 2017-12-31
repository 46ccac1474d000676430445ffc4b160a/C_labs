#include <stdio.h>
#include "conio.h"

bool YesNo()
{
    for(;;)
        switch (getch())
        {
        case 'y': printf("y\n\n"); return 1;
        case 'n': printf("n\n\n");  return 0;
        }
}

int main()
{
    double x, y;

    char ch;

    do
    {
        printf("X << ");
        scanf("%lf", &x);

        printf("Y << ");
        scanf("%lf", &y);

        if (
             (
               (x >= -1. && x <= 0. && y <= 1. && y >= 0.)

               ^

               (x <= 1. && x >= 0. && y >= -1. && y <= 0.)
             )

             &&

             (x*x + y*y <= 1.)
            ) printf("\nТочка входит в ОДЗ\n");
        else printf("\nТочка НЕ входит в ОДЗ\n");

        printf("\nПовторить? y/n\t");

    } while (YesNo());

    return 0;
}
