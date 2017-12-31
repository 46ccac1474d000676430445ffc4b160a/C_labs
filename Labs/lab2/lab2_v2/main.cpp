#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double rnd(short n = 3)
{
    double num;


    int temp = 10;
    for (int i = 1; i <= n; i++) temp *= 10;

    do
    {
        num = rand() % temp;
    } while (num == 0.);

    for (short i = 1; i <= n; i++) num *= 0.1;

    return num;
}

int main()
{
    srand(time(0));

    double a = rnd(7);
    double b = rnd(7);
    double c = rnd(7);
    double d = rnd(7);

    int n;
    do
    {
        n = rand() % 5;
    } while (n == 1);

     printf("a = %lf\nb = %lf\nc = %lf\nd = %lf\nn = %d\n\n", a, b, c, d, n);

    double x, y;

    printf("Enter X: ");
    scanf("%lf", &x);
    printf("\nEnter Y: ");
    scanf("%lf", &y);

    double t1 = (1./c) * ( ((b/a) * log(a*x + b)) + ((d/y) * log(y*x + d)) );

    double t2 = ( 1./( a*(n-1)) ) * ( sin(a*x)/pow(cos(a*x), n-1) );

    printf("\n\nt1 = %lf\n\nt2 = %lf\n", t1, t2);

    return 0;
}
