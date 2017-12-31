#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    const int N = 9;

    int arr[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 100;
            printf("%5d", arr[i][j]);
        }
        putchar('\n');
    }

    printf("\n\n\n");

     for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) printf("%5d", arr[j][i]);
        putchar('\n');
    }

    return 0;
}
