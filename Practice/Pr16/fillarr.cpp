#include <stdlib.h>

#include "pr16.h"

void fillArr50(int *arr, int n)
{
    while(n--) *arr++ = -50 + (rand() % 51);
}

void fillArr50(double *arr, int n)
{
    while(n--) *arr++ = double(-5000 + (rand() % 5100)) / 100.;
}
