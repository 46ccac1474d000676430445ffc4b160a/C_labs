#include <stdio.h>

void firstword(const char *s1, char *s2)    // Функция выделяет первое слово из строки
{
    while (*s1 == ' ') s1++;
    while (*s1 != ' ' && *s1) *s2++ = *s1++;
    *s2 = 0;
}

int main()
{
    char s1[] = " word ";
    char s2[20];

    firstword(s1, s2);

    printf(">%s<\n", s2);

    return 0;
}
