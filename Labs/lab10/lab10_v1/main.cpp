#include <stdio.h>

int wordcount(const char* s)    // Функция подсчитывает количество слов в строке
{
    int counter = 0;

   while (1)
   {
        while(*s == ' ') s++;
        if (!(*s)) break;
        counter++;
        while(*s && *s != ' ') s++;
   }

    return counter;
}

int main()
{
    printf("%d\n", wordcount(" Hello world! "));
    return 0;
}
