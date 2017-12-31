#include <stdio.h>

struct Complex
{
    double real;
    double imaginary;
};

void printComplex(const Complex &n, bool new_line = 0) { printf("(%g + %gi)", n.real, n.imaginary); if (new_line) putchar('\n');}

double sum(double a, double b) { return a + b; }

Complex sum(const Complex &a, const Complex &b)
{
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;

    return c;
}

int main()
{
    printf("%f + %f = %f\n\n", 15.9, 60.83, sum(15.9, 60.83));

    Complex a = {45.5, 17.13}, b = {192.168, 1.1}, c;

    printComplex(a);
    printf(" + ");
    printComplex(b);
    printf(" = ");
    printComplex(sum(a, b), 1);

    return 0;
}
