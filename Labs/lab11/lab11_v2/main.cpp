#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void FillArray(int**, int); //заполнение

void PrintArray(int**, int);    //вывод

void SimmetricPrintArray(int**, int);   //вывод симетрично главной диагонали



int main()
{
    srand(time(0));

    int N = 0;

    printf("N >> ");
    while ( !scanf("%d", &N) ) getchar();

    printf("\n\n\n");

    int** arr = new int*[N];
    for (int i = 0; i < N; i++) arr[i] = new int[N];

    FillArray(arr, N);

    PrintArray(arr, N);

    printf("\n\n\n");

     SimmetricPrintArray(arr, N);

     for (int i = 0; i < N; i++) delete [] arr[i];
     delete [] arr;

    return 0;

}   // MAIN


void FillArray(int** a, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) a[i][j] = rand() % 100;
}


void PrintArray(int** a, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) printf("%5d", a[i][j]);
        putchar('\n');
    }
}


void SimmetricPrintArray(int** a, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) printf("%5d", a[j][i]);
        putchar('\n');
    }
}
