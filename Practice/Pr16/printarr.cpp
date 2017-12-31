#include <stdio.h>

#include "pr16.h"

void printArr(int *arr, int n, int new_line = 0)
{
    while(n--) printf("%d ", *arr++);
    while (new_line--) putchar('\n');
}

void printArr(double *arr, int n, int new_line = 0)
{
    while(n--) printf("%g ", *arr++);
    while (new_line--) putchar('\n');
}
