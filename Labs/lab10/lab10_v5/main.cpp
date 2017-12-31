#include <stdio.h>

void divstr(const char *s, int c, char *s1, char *s2)   // Функция разбивает строку на две части: до первого вхождения заданного символа и после него
{
    while (*s && *s != c) *s1++ = *s++;
    *s1 = 0;
    s++;
    while (*s) *s2++ = *s++;
    *s2 = 0;
}

int main()
{
    char s1[20];
    char s2[20];

    divstr("abcdef", 'a', s1, s2);

    printf(">%s<\t>%s<\n", s1, s2);

    return 0;
}
