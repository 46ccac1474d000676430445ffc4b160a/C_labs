#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    const int N = 100;

    int* arr = new int[N];

    int s = 0, mn, mx;

    for (int i = 0; i < N; i++) arr[i] = -50 + rand() % 101;

    mn = mx = *arr;
    for (int i = 0; i < N; i++)
    {
        if (mn > arr[i]) mn = arr[i];

        if (mx < arr[i]) mx = arr[i];

        s += arr[i];
    }

     for (int i = 0; i < N; i++) printf("%5d", arr[i]);
     printf("\n\n");

    printf("Сумма всех элементов массива равна %d\n", s);
    printf("Среднее арифметическое всех элементов равна %.2lf\n", ((double)s) / N );
    printf("Минимальный элемент массива равен %d\n", mn);
    printf("Максимальный элемент массива равен %d\n\n\n", mx);

    printf("a[0]\t= %d\t\t\t1-й по счету элемент массива\n", arr[0]);
    printf("a[2]\t= %d\t\t\t3-й по счету элемент массива\n\n", arr[2]);
    printf("&a[5]\t= %p\t\tадрес 6-го по счету элемент массива\n", &arr[5]);
    printf("*a\t= %d\t\t\t1-й по счету элемент массива\n\n", *arr);
    printf("*(a+5)\t= %d\t\t\t6-й по счету элемент массива\n", *(arr+5));
    printf("a+5\t= %p\t\tадрес 6-го по счету элемент массива\n\n", arr+5);
    printf("*a+5\t= %d\t\t\t1-й по счету элемент массива + 5\n", *arr+5);
    printf("a\t= %p\t\tадрес 1-го по счету элемент массива/начала массива\n\n", arr);

    delete [] arr;

    return 0;
}
