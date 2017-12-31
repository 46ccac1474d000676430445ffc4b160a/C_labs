#include <stdio.h>

float mult(int n...)
{
    float s = 1.f;

    union
    {
        int *ipt;
        float *fpt;
    } p;
    p.ipt = &n;
    p.ipt++;

    while (n--)
    {
        printf("%f\n", *p.fpt);
        s *= *p.fpt++;
    }

    return s;
}

int main()
{
    printf("\n%f\n\n", mult(3, 1.f, 2.f, 3.f));
    printf("\n%f\n\n", mult(7, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f));
    printf("\n%f\n\n", mult(11, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f));

    return 0;
}
