#include <stdio.h>

double ABS(double value) { return (value < 0.) ? -value :  value; }

void count_num(char acr)
{
    double e, s = 0.;
    long long i = 0;

    double acrn = 1.;
    for (char j = 0; j < acr; j++) acrn *= 0.1;



    int k = -1;

    for (i; i < 10; i++)
    {
        s += e = k*((i+1.)/(i*i*i + 2.));
        k = -k;
    }



    printf("\nСумма первых десяти членов ряда = %.10lf\n", s);



    k = -1;
    do
    {
        s += e = k*((i+1.)/(i*i*i + 2.));
        i++;
        k = -k;
        //printf("\n%.15lf", e);
    } while (ABS(e) > acrn);



    printf("\nСумма ряда = %.15lf\t Число итераций = %d\n\n", s, i);
}


int main()
{
    count_num(6);

    return 0;
}
