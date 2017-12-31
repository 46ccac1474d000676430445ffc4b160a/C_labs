#include <stdio.h>

#include <iostream>
using namespace std;

#define Step printf("\n\t\tLine: %d\n", __LINE__);

int sum1(int n, ...)
{
    int *p = &n+1, s = 0;
    while(n--) s += *p++;
    return s;
}

int sum2(int val, ...)
{
    int *p = &val, s = 0;
    while(*p) s += *p++;
    return s;
}

union Uptr
{
    int *ipt;
    double *dpt;
};

double sum3(int sw, ...)
{
    double S= 0.;

    union
    {
        int *ipt;
        double *dpt;
    }p;
    p.ipt = &sw;

    while(1)
        switch (*p.ipt++)
        {
        case 1:
            S += *p.ipt++;
            break;

        case 2:
            S += *p.dpt++;
            break;

        default: return S;
        }
}

double sumArr(int sw, ...)
{
    double s = 0.;

    union
    {
        int *ipt;
        double **dpt;
    }p;
    p.ipt = &sw;

    int n;
    while(n  = *p.ipt++)
    {
        for (int i = 0; i < n; i++) s += (*p.dpt)[i];
        p.dpt++;
    }

    return s;
}


int main()
{
    printf("Sum1 = %d\n", sum1(5, 5, 0, 5, 5, 5));
    printf("Sum2 = %d\n", sum2(5, 5, 0, 5, 5, 5));
    printf("Sum3 = %f\n\n", sum3(1,5, 2,5.2, 2,5.3, 0));

    double arr1[1] = {5.}, arr2[2] = {5., 5.}, arr3[3] = {5., 5., 5.};
    printf("SumArr = %f\n", sumArr(1,arr1, 2,arr2, 3,arr3, 0));



    return 0;
}

