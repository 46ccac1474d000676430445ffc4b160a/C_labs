#include <stdio.h>

void bin(unsigned short val)
{
    putchar('[');
    for (char i = sizeof(val)*8-1; i >= 1; i--)
        if (i % 8) putchar( (val >> i & 1) + '0' );
        else printf("%c][", (val >> i & 1) + '0');
    printf("%c]\n", (val & 1) + '0' );
}

void convert(unsigned short num, unsigned short base)
{
    if (num / base) convert(num / base, base);
    putchar((num % base < 10) ? (num % base + '0') : (num % base - 10 + 'A'));
}



unsigned short process(unsigned short num, unsigned short range, unsigned short shift)
{
    num &= range;
    num <<= shift;
    return num;
}


void first_part()
{
    unsigned short pack;
    unsigned short C, E, I, P, K;

    printf("Введите маску канала (0..15) -> ");
    scanf("%hu", &C);

    printf("Введите маску внешнего прерывания (0..1) -> ");
    scanf("%hu", &E);

    printf("Введите маску внутреннего прерывания (0..1) -> ");
    scanf("%hu", &I);

    printf("Введите маску программного прерывания (0..1) -> ");
    scanf("%hu", &P);

    printf("Введите ключ защиты памяти (0..7) -> ");
    scanf("%hu", &K);

    pack |= process(C, 15, 12);
    pack |= process(E, 1, 11);
    pack |= process(I, 1, 10);
    pack |= process(P, 1, 9);
    pack |= process(K, 7, 3);


    printf("\nСлово состояния устройства = 0x");
    //bin(pack);
    convert(pack, 16);
    putchar('\n');
}



void second_part()
{
    int temp;
    unsigned short pack;
    unsigned short C, E, I, P, K;

    printf("Введите cлово состояния программы (0..0xFFFF) -> ");
    scanf("%i", &temp);

    pack = temp;

    C = (pack >> 12) & 15;
    E = (pack >> 11) & 1;
    I = (pack >> 10) & 1;
    P = (pack >> 9) & 1;
    K = (pack >> 3) & 7;

    printf("\nМаска канала: %hu\n", C);
    printf("Маска внешнего прерывания: %hu\n", E);
    printf("Маска внутреннего прерывания: %hu\n", I);
    printf("Маска программного прерывания: %hu\n", P);
    printf("Ключ защиты памяти: %hu\n", K);
}


int main()
{
    /* */

    first_part();

    printf("\n\n");

    /* */

    second_part();

    /* */

    return 0;
}
