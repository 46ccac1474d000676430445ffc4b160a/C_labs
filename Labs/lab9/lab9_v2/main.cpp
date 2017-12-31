#include <stdio.h>
#include <string.h>
#include "firm.h"

void output(Firm firm)
{
    printf("%-20s\t%-16d\t%-23lld\t\t%.2f\n", firm.name, firm.product, firm.sales, firm.market);
}


int strcmp(const char *s1, const char *s2)
 {
	while(*s1)
        if(*s1-*s2) return *s1-*s2;
		else
        {
			s1++;
            s2++;
		}

return 0;   // равенство
}



int main()
{
    int N = 0;
    Firm* db;

    const char* dir = "db.txt";

    FILE* f;

    if ( (f = fopen(dir, "rt")) == nullptr)
    {
        printf("Error! File \"%s\" not found!", dir);
        return 0;
    }

    char tempstr[256];
    for(; !feof(f); N++) fgets(tempstr, sizeof(tempstr), f);
    rewind(f);

    db = new Firm[N];

    for (int i = 0; i < N; i++)
        fscanf(f, "%s %d %ld %f",
                                                    db[i].name,
                                                    &db[i].product,
                                                    &db[i].sales,
                                                    &db[i].market
                                                );

    for(int i = 0; i < N-1; i++)
        for(int j = i; j < N; j++)
            if (strcmp(db[i].name, db[j].name))
            {
                Firm temp = db[i];
                db[i] = db[j];
                db[j] = temp;
            }

    printf("\t\t\t\t\tФирмы-производители СКБД (%d)\n\n", N);

    printf("Фирма\t\t\tКол-во продуктов\tГодовой объём продаж ($)\tЧасть рынка (%)\n");

    for (int i = 0; i < N; i++) output( db[i] );

    printf("\n\n");

    delete [] db;

    return 0;
}
