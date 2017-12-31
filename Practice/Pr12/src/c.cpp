#include "header.h"

int f3()
{
    static int see_stat = 0;
    see_stat++;
    printf("f3: now see_stat = %d\n", see_stat);
}
