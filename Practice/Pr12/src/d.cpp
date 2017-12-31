#include "header.h"

bool flag;


int main()
{

    srand(time(0));
    flag = 1;
    puts("Now flag = 1");

    int n = rand() % 11 + 2;
    for (int i = 0; i < n; i++)
    {
        switch (rand()%3)
        {
        case 0: f1();
            break;
        case 1: f2();
            break;
        case 2: f3();
            break;
        }
    }

    return 0;
}
