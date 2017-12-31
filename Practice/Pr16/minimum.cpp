#include "pr16.h"

int minimum(int *arr, int n)
{
    int m = *arr;
    while(--n) if (*++arr < m) m = *arr;
    return m;
}

double minimum(double *arr, int n)
{
    double m = *arr;
    while(--n) if (*++arr < m) m = *arr;
    return m;
}
