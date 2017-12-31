#include <stdio.h>

void strcat(char* s1, const char* s2)   // Функция дописывает одну строку в конец другой
{
   while(*s1++); s1--;
   while (*s1++ = *s2++);
   s1 = 0;
}


int main()
{
    char s1[26] = "First_string";
    char s2[14] = "Second_string";

    strcat(s1, s2);

    printf("BEGIN->%s<-END\n", s1);

    return 0;
}
