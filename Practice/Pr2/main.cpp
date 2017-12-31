#include <stdio.h>
#include <math.h>

int main()
{
    double A;

    printf("Enter a: ");
    scanf("%lf", &A);

    double Y = pow(cos(3./8. * M_PI - A/4. ), 2.) -  pow(cos(11./8. * M_PI + A/4.), 2.);

    double Z = (pow(2., .5) / 2. * sin(A)) / 2.;

    printf("\nResult\nY = %lf\nZ = %lf\nY / Z = %lf\n", Y, Z, Y/Z);

    return 0;
}
