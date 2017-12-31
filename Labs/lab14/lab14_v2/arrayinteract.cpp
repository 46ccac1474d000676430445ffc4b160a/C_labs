#include "firm.h"

#include <stdio.h>

void showFirm(const Firm &f, int new_line_before, int new_line_after)
{
    while(new_line_before--) putchar('\n');
    printf("%-30s\t%-16ld\t%-23lld\t\t%.2f", f.name, f.product, f.sales, f.market);
    while(new_line_after--) putchar('\n');
}

void showFirmArray(const Firm *db, int N, int new_line_before, int new_line_after)
{
    while(new_line_before--) putchar('\n');
    for (int i = 1; i < N; i++) { printf("%-3d  ", i); showFirm(*db++, 0, 1); }
    printf("%-3d  ", N);
    showFirm(*db, 0, 0);
    while(new_line_after--) putchar('\n');
}

int fillArrayFromFile(Firm *&db, const char* path)
{
    FILE *f;
    int N = 0;

    if ( (f = fopen(path, "rt")) == nullptr ) return -1;  //если невозможно открыть файл

    char buf[1024] = {0};

    while(!feof(f)) { fgets(buf, 1024, f); N++; }
    rewind(f);

    db = new Firm[N];

    for (int i = 0; i < N; i++)
        fscanf(f, "%s %ld %lld %f",
                    db[i].name,
                    &db[i].product,
                    &db[i].sales,
                    &db[i].market
                );

    fclose(f);
    return N;   //кол-во элементов в массиве
}

void appendToArray(Firm *&db, const Firm &f, int &N)
{
    Firm *tdb = new Firm[++N];

    for (int i = 0; i < N-1; i++) tdb[i] = db[i];
    tdb[N-1] = f;

    delete [] db;

    db = tdb;
}

void eraseFromArray(Firm *&db, int index, int &N)
{
    Firm *tdb = new Firm[--N];

    for (int i = 0; i < index; i++) tdb[i] = db[i];
    for (int i = index+1; i < N+1; i++) tdb[i-1] = db[i];

    delete [] db;

    db = tdb;
}
