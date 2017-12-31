#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include "conio.h"

#include "lab.h"


std::vector <Firm> database;


bool YesNo()
{
    while (1)
        switch (getch())
        {
            case 'y': printf("y\n"); return 1;
            case 'n': printf("n\n"); return 0;
        }
}


bool compare(const char *s1, const char* s2)
{
    s1--;
    s2--;
    while ( (*++s1) && (*++s2) )
    {
        char t1 = *s1;
        char t2 = *s2;

        if ( isalpha(t1) && islower(t1) ) t1 = toupper(t1);
        if ( isalpha(t2) && islower(t2) ) t2 = toupper(t2);

        if (t1 < t2) return 1;

    }
    return 0;
}


Firm input()
{
    Firm firm;

    printf("\nВведите название фирмы: ");
    scanf("%s", firm.name);

    printf("Введите колличество продуктов: ");
    scanf("%d", &firm.product);

    printf("Введите годовой объём продаж ($): ");
    scanf("%lld", &firm.sales);

    printf("Введите часть рынка (\%): ");
    scanf("%f", &firm.market);

    return firm;
}


void DatabasePushBack()
{
    printf("Вводите данные\n");

    do
    {
        database.push_back( input() );
        printf("\nВвести ещё? y/n\t");
    } while (YesNo());

        for (int i = 0; i < database.size(); i++)
            for (int j = 0; j < database.size(); j++)
                if ( compare(database[i].name, database[j].name ) )
                {
                    Firm temp = database[i];
                    database[i] = database[j];
                    database[j] = temp;
                }
}


void output(Firm firm)
{
    printf("%-20s\t%-16d\t%-23lld\t\t%.2f\n", firm.name, firm.product, firm.sales, firm.market);
}


void outputTable()
{
    printf("\n\n\t\t\t\t\tФирмы-производители СКБД\n\n");

    printf("Фирма\t\t\tКол-во продуктов\tГодовой объём продаж ($)\tЧасть рынка (%)\n");

    for (int i = 0; i < database.size(); i++) output( database[i] );

    printf("\n\n");
}


void interface()
{
    while(1)
    {
        system("clear");

        printf("Меню:\n\n1. Добавить в базу данных новые элементы\n2. Вывести на экран базу данных\n3. Вывести на экран 1 элемент базы данных\n4. Удалить элемент из базы данных\n5. Завершить работу программы\n\n");

        printf("Введите номер опции >> ");

        char sw;
        while (sw < '1' || sw > '5') sw = getch();
        printf("%c\n\n", sw);

        switch (sw)
        {
            case '1':
               {
                    system("clear");
                    DatabasePushBack();
                    printf("\nВернуться в меню? y/n\t");
                    if (YesNo()) break;
                    else return;
               }

            case '2':
                {
                    system("clear");
                    if (database.size() == 0)
                    {
                        printf("База данных пуста!\n\nВернуться в меню? y/n\t");
                        if (YesNo()) break;
                        else return;
                    }
                    outputTable();
                    printf("\nВернуться в меню? y/n\t");
                    if (YesNo()) break;
                    else return;
                }

            case '3':
                {
                    system("clear");
                    if (database.size() == 0)
                    {
                        printf("База данных пуста!\n\nВернуться в меню? y/n\t");
                        if (YesNo()) break;
                        else return;
                    }
                    printf("Введите номер элемента, который желаете посмотреть >> ");
                    int N = 0;
                    while (!N || N > database.size() ) scanf("%d", &N);
                    printf("\n\n\t\t\t\t\tФирмы-производители СКБД\n\nФирма\t\t\tКол-во продуктов\tГодовой объём продаж ($)\tЧасть рынка (%)\n");
                    output(database[N-1]);
                    printf("\nВернуться в меню? y/n\t");
                    if (YesNo()) break;
                    else return;
                }

            case '4':
                {
                    system("clear");
                    if (database.size() == 0)
                    {
                        printf("База данных пуста!\n\nВернуться в меню? y/n\t");
                        if (YesNo()) break;
                        else return;
                    }
                    printf("Введите номер элемента, который желаете удалить >> ");
                    int N = 0;
                    while (!N || N > database.size() ) scanf("%d", &N);
                    database.erase(database.begin() + N-1);
                    printf("\nЭлемент удалён!\n\nВернуться в меню? y/n\t");
                    if (YesNo()) break;
                    else return;
                }

            case '5': return;
        }

        sw = 0;
    }

}
