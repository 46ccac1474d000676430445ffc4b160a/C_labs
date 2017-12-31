#include <stdio.h>

typedef unsigned char uchar;

void bin(uchar num)
{
    for (int i = sizeof(num)*8 - 1; i >= 0; i--) putchar(((num >> i) & 1 )+ '0');
}

void convert(uchar num, uchar base)
{
    if (num / base) convert(num / base, base);
    putchar((num % base < 10) ? (num % base + '0') : (num % base - 10 + 'A'));
}

int DBL(int value)
{
    return value << 1;
}

int invert_sign(int num)
{
    num = ~num;
    return num++;
}

int adding(int val1, int val2)
{
    int s, bp = 0, buf = 0;

    for (int i = 0; i <  sizeof(int)*8; i++)
    {
        s = ( ( (val1 >> i) & 1 ) + ( (val2 >> i) & 1 ) + bp );
        bp = s >> 1;
        buf |= (s & 1) << i;
    }

    return buf;
}


int main()
{
    for (uchar i = 0; i < 32; i++)
    {
        convert(i, 10);
        putchar('\t');
        bin(i);
        putchar('\t');
        convert(i, 8);
        putchar('\t');
        convert(i, 16);
        putchar('\n');
    }

   printf("\n\n%d\n\n", adding(142, -28));

    return 0;
}
