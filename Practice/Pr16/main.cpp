#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pr16.h"

int main()
{
    srand(time(0));

    const int N = 100;

    int iArr[N];
    fillArr50(iArr, N);
    printArr(iArr, N, 2);
    printf("min value of int array = %d\n\n\n", minimum(iArr, N));

    double fArr[N];
    fillArr50(fArr, N);
    printArr(fArr, N, 2);
    printf("min value of double array = %g\n", minimum(fArr, N));

    return 0;
}
