#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

   const int N = 4;

   int arr[N][N],
        col,    //столбец
        mn, //минимальный элемент
        line,   //строка
        mx, //максимальный элемент
        s_mn = 0,   //главная диагональ
        s_in = 0;   //побочная диагональ


   for (char i = 0; i < N; i++) //заполнение и вывод
   {
       for (char j = 0; j < N; j++)
       {
           arr[i][j] = -50 + (rand()  % 101);
           printf("%5d", arr[i][j]);
       }
        putchar('\n');
        putchar('\n');
   }


   mn = mx = arr[0][0];

   for (char i = 0; i < N; i++)
   {
       for (char j = 0; j < N; j++)
       {
           if (mn > arr[i][j])
           {
               mn = arr[i][j];
               col = j;
           }

           if (mx < arr[i][j])
           {
               mx = arr[i][j];
               line = i;
           }
       }

       s_mn += arr[i][i];
       s_in += arr[i][N-i-1];
   }

   printf("\n\nМинимальный элемент равен %d\n", mn);
   printf("Столбец минимального элемента: %d\n\n", col);
   printf("Максимальный элемент равен %d\n", mx);
   printf("Строка максимального элемента: %d\n\n", line);
   printf("Сумма главной диагонали равна %d\n", s_mn);
   printf("Сумма побочной диагонали равна %d\n\n", s_in);

    return 0;
}
