#include <stdio.h>
#include <math.h>
#include <float.h>

void out(int);

int main()
{
    printf("Type:\t\tByte:\tBit:\tMin:\t\tMax:\n\n");

    printf("char\t\t");
    out(sizeof(char));

    printf("short int\t");
    out(sizeof(short));

    printf("long int\t");
    out(sizeof(long));

    printf("float\t\t%d\t%d\t%-15E\t%-15E\n",
           sizeof(float),
           sizeof(float) * 8,
           -FLT_MIN,
           FLT_MAX);

    printf("double\t\t%d\t%d\t%-15E\t%-15E\n",
           sizeof(double),
           sizeof(double) * 8,
           -DBL_MIN,
           DBL_MAX);

    return 0;
}


void out(int _size)
{
    printf("%d\t%d\t%-15d\t%-15d\n",
           _size,
           _size * 8,
           -(int)pow(2, _size * 8 - 1),
           (int)pow(2, _size * 8 - 1)-1);
}
