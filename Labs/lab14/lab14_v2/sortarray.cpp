#include "firm.h"

#include <ctype.h>

bool compByNameFrom_A(const Firm &f1, const Firm &f2)
{
    const char *st1 = f1.name, *st2 = f2.name;
    while(*st1 && *st2)
    {
        if(toupper(*st1)-toupper(*st2) > 0) return 1;
        if (toupper(*st1)-toupper(*st2) < 0) return 0;
        st1++;
        st2++;
    }
    return 0;
}

bool compByNameTo_A(const Firm &f1, const Firm &f2)
{
    const char *st1 = f1.name, *st2 = f2.name;
    while(*st1 && *st2)
    {
        if(toupper(*st1)-toupper(*st2) < 0) return 1;
        if (toupper(*st1)-toupper(*st2) > 0) return 0;
        st1++;
        st2++;
    }
    return 0;
}

bool compByProductFrom_0(const Firm &f1, const Firm &f2)
{
    return (f1.product > f2.product) ? 1 : 0;
}

bool compByProductTo_0(const Firm &f1, const Firm &f2)
{
    return (f1.product < f2.product) ? 1 : 0;
}

bool compBySalesFrom_0(const Firm &f1, const Firm &f2)
{
    return (f1.sales > f2.sales) ? 1 : 0;
}

bool compBySalesTo_0(const Firm &f1, const Firm &f2)
{
    return (f1.sales < f2.sales) ? 1 : 0;
}

bool compByMarketFrom_0(const Firm &f1, const Firm &f2)
{
    return (f1.market > f2.market) ? 1 : 0;
}

bool compByMarketTo_0(const Firm &f1, const Firm &f2)
{
    return (f1.market < f2.market) ? 1 : 0;
}

void sortArray(Firm *db, int N, bool (*comp)(const Firm&, const Firm&))
{
    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++)
            if (comp(db[i], db[j]))
            {
                Firm t = db[i];
                db[i] = db[j];
                db[j] = t;
            }
}
