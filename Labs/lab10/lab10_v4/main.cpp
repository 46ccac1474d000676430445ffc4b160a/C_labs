#include <stdio.h>
#include <ctype.h>

int strcomp(const char *s1, const char *s2)   // Функция сравнивает две строки, игнорируя различия в регистрах
{
    while(*s1 && *s2)
    {
        int c1 = toupper(*s1++), c2 = toupper(*s2++);
        if (c1 - c2) return c1 - c2;    // если <0, то s1 по алф. ближе к A, если >0, то s2 по алф. ближе к А
    }
    return 0;   // если строки одинаковые
}

int main()
{
    printf("%d\n", strcomp(" StR11", " str19"));

    return 0;
}
