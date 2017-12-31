#include <stdio.h>

void int_range(int num)
{
    printf("Степени числа %d от 0 до 10\n\n", num);

    int temp = 1;
    for (char i = 0; i <= 10; i++)
    {
        printf("%d в степни %d = %d\n", num, i, temp);
        temp *= num;
    }
}

double ABS(double value)
{
    if (value < 0.) return -value;
    else return value;
}

void count_Pi(char acr)
{
    double e = 1., s = 0.;
    long long i = 0;

    double acrn = 1.;
    for (char j = 0; j < acr; j++) acrn *= 0.1;

    do
    {
        if (i % 2) e = -1./(2.*i + 1.);
        else e = 1./(2.*i + 1.);
        s += e;
        i++;
    } while (ABS(e) > acrn);

    printf("\n\nPi = %.15lf\t i = %d\n\n", s*4, i);
}

int main()
{
    int_range(2);

    count_Pi(7);

    return 0;
}
