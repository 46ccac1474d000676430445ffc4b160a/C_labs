#include "header.h"

extern bool flag;

int f1()
{
    flag = !flag;
    if (flag) puts("f1: changed flag to TRUE");
    else puts("f1: changed flag to FALSE");
}
