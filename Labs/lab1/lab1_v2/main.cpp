#include <stdio.h>

struct Firm
{
    char* name;
    int product;
    long long sales;
    float market;
};

Firm input()
{
    Firm firm;
    firm.name = new char[256];

    printf("\nВведите название фирмы: ");
    scanf("%s", firm.name);

    printf("Введите колличество продуктов: ");
    scanf("%d", &firm.product);

    printf("Введите годовой объём продаж ($): ");
    scanf("%lld", &firm.sales);

    printf("Введите часть рынка (%): ");
    scanf("%f", &firm.market);

    return firm;
}

void output(Firm *firm)
{
    printf("%-20s\t%-16d\t%-23lld\t\t%.2f\n", firm->name, firm->product, firm->sales, firm->market);
}

int main()
{
    Firm database[3];

    printf("Вводите данные\n");

    for (int i = 0; i < 3; i++) database[i] = input();

    printf("\n\n\t\t\t\t\tФирмы-производители СКБД\n\n");

    printf("Фирма\t\t\tКол-во продуктов\tГодовой объём продаж ($)\tЧасть рынка (%)\n");

    for (int i = 0; i < 3; i++) output(database + i);

    printf("\n\n");

    for (int i = 0; i < 3; i++) delete [] database[i].name;


    return 0;
}
