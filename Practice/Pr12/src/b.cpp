#include "header.h"

extern bool flag;

int f2()
{
    flag = !flag;
    if (flag) puts("f2: changed flag to TRUE");
    else puts("f2: changed flag to FALSE");
}
