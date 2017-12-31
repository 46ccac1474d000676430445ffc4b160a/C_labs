#include <stdio.h>

int main(int agrc, char** agrv)
{
    printf("c = %d\n", agrc);
    for (int i = 0; i < agrc; i++) printf("%s\n", agrv[i]);
    if (agrc != 3) { printf("Use: copy file1 file2"); return 0; }

    FILE *in, *out;

    if( (in = fopen(agrv[1], "rb")) == nullptr ) { printf("Can't open \"%s\"\n", agrv[1]); return 0; }
    if( (out = fopen(agrv[2], "wb")) == nullptr ) { printf("Can't write \"%s\"\n", agrv[2]); return 0; }

    char buf[256];

    while(!feof(in)) fwrite(buf, 1, fread(buf, 1, 256, in), out);

    printf("Good!\n");

    return 0;
}
