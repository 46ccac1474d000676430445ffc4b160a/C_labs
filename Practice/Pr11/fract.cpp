#include "fract.h"


long BCD(long a, long b)
{
    while (a && b)
        if (a >= b) a %= b;
        else b %= a;

    return a | b;
}


Fract sum(const Fract &a, const Fract &b)
{
    Fract t;

    t.Num = a.Num * b.DeNum + b.Num * a.DeNum;

    t.DeNum = b.DeNum * a.DeNum;

    int bcd = BCD(t.Num, t.DeNum);
    t.Num /= bcd;
    t.DeNum /= bcd;

    return t;
}

Fract sub(const Fract &a, const Fract &b)
{
    Fract t;

    t.Num = a.Num * b.DeNum - b.Num * a.DeNum;

    t.DeNum = b.DeNum * a.DeNum;

    int bcd = BCD(t.Num, t.DeNum);
    t.Num /= bcd;
    t.DeNum /= bcd;

    return t;
}

Fract mul(const Fract &a, const Fract &b)
{
    Fract t;

    t.Num = a.Num *b.Num;

    t.DeNum = a.DeNum * b.DeNum;

    int bcd = BCD(t.Num, t.DeNum);
    t.Num /= bcd;
    t.DeNum /= bcd;

    return t;
}

Fract div(const Fract &a, const Fract &b)
{
    Fract t;

    t.Num = a.Num * b.DeNum;

    t.DeNum = a.DeNum * b.Num;

    int bcd = BCD(t.Num, t.DeNum);
    t.Num /= bcd;
    t.DeNum /= bcd;

    return t;
}

void input(Fract &a)
{
    printf("Integer << ");
    int b;
    scanf("%d", &b);
    printf("Numinator << ");
    scanf("%d", &a.Num);
    printf("Denuminator << ");
    scanf("%d", &a.DeNum);

    a.Num += b * a.DeNum;
}

void show(const Fract &a)
{
    if (a.Num/a.DeNum) printf("%d", a.Num/a.DeNum);
    if (a.Num%a.DeNum) { if (a.Num/a.DeNum) putchar(' '); printf("%d/%d", a.Num%a.DeNum, a.DeNum); }
    if (!(a.Num/a.DeNum) && !a.Num) puts("null");
}
