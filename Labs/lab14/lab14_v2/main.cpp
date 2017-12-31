#include <stdio.h>
#include "conio.h"

#include "firm.h"


bool askContinue()
{
    printf("Continue? (y/n) ");
    while(1)
        switch(getch())
        {
            case 'y': putchar('y'); return 1;
            case 'n': putchar('n'); return 0;
        }
}

int askIndex(int N)
{
    printf("\tInput index of element (1-%d) >> ", N);
    int index = 1;
    while(1)
    {
        scanf("%d", &index);
        if (index < 1 || index > N) printf("\tOut of range! Try again >> ");
        else return --index;
    }
}

typedef bool (*comp)(const Firm&, const Firm&);
comp AskSort()
{
    puts("   Sort by:\n    1. Name A-Z\n    2. Name Z-A\n    3. Product 0-9\n    4. Product 9-0\n    5. Sales 0-9\n    6. Sales 9-0\n    7. Market 0-9\n    8. Market 9-0");
    while(1)
        switch(getch())
        {
            case '1': puts("    Sorted by name A-Z\n"); return compByNameFrom_A;
            case '2': puts("    Sorted by name Z-A\n"); return compByNameTo_A;
            case '3': puts("    Sorted by product 0-9\n"); return compByProductFrom_0;
            case '4': puts("    Sorted by product 9-0\n"); return compByProductTo_0;
            case '5': puts("    Sorted by sales 0-9\n"); return compBySalesFrom_0;
            case '6': puts("    Sorted by sales 9-0\n"); return compBySalesTo_0;
            case '7': puts("    Sorted by market 0-9\n"); return compByMarketFrom_0;
            case '8': puts("    Sorted by market 9-0\n"); return compByMarketTo_0;
        }
}

Firm inputFirm()
{
    Firm f;
    printf("\n  Input company name >> ");
    scanf("%s", f.name);
    printf("  Input number of products >> ");
    scanf("%ld", &f.product);
    printf("  Input volume of sales($) >> ");
    scanf("%lld", &f.sales);
    printf("  Input part of market(%%) >> ");
    scanf("%f", &f.market);

    return f;
}


int main()
{
    Firm *db;

    const char *path = "db.txt";

    int N = fillArrayFromFile(db, path);

    if (N < 0)
    {
        printf("Error! File \"%s\" not found!", path);
        return 0;
    }
    else puts("File succesfully opened!");


    bool eflag = 1;
    while(eflag)
    {

        puts("\n\nMenu:\n 1. Show all database\n 2. Show element by index\n 3. Sort database by column\n 4. Append element to database\n 5. Erase element by index\n ESC - exit");

        bool f = 1;
        while(f)
            switch(getch())
            {
                case '1':
                {
                    puts("1");
                    printf("\t\t\t\t\tФирмы-производители СКБД (%d)\n\n", N);
                    printf("No   Фирма\t\t\t\tКол-во продуктов\tГодовой объём продаж ($)\tЧасть рынка (%)\n");
                    showFirmArray(db, N, 1, 2);
                    f = 0;
                    eflag = askContinue();
                } break;

                case '2':
                {
                    puts("2");
                    showFirm(db[askIndex(N)], 1, 2);
                    f = 0;
                    eflag = askContinue();
                } break;

                case '3':
                {
                    puts("3");
                    sortArray(db, N, AskSort());
                    f = 0;
                } break;

                case '4':
                {
                    puts("4");
                    appendToArray(db, inputFirm(), N);
                    f = 0;
                } break;

                case '5':
                {
                    puts("5");
                    if (N > 0) eraseFromArray(db, askIndex(N), N);
                    else
                    {
                        puts("   Database is empty!");
                        eflag = askContinue();
                    }
                    f = 0;
                } break;

                case 27:
                {
                    f = 0;
                    eflag = 0;
                } break;
            }

    }


    delete [] db;

    return 0;
}
