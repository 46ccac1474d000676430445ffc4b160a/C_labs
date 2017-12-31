#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    const int N = 200;

    char arr[N];


//    putchar('\t');
//    for (int i = 0; i <= 9; i++) printf("%4d ", i);
//    putchar('\n');


    for (int i = 0; i < N; i++)
    {
        arr[i] = -50 + (rand() % 100);


//        if (i % 10 == 0) printf("\n[%3d]\t%4d", i, arr[i]);
//        else printf("%4d ", arr[i]);
    }


    int counter = 0;

    //putchar('\n');

    for (int i = 0; i < N-1; i++)
        if (arr[i] == arr[i+1])
        {
            counter++;


            //printf("\n[%d] = %d", i, arr[i]);
        }

    printf("\n\nКоличество пар соседних элементов с одинаковыми значениями равно %d\n\n", counter);

    return 0;
}
