#include <stdio.h>

int replace_word(char*& mst, const char* fst, const char* rst)
{
    char* t_mst = mst;
    const char* t_fst = fst, *t_rst = rst;

    int mN = 0, mfN = 0, fN = 0, rN = 0;

    while(*t_mst)
        if (*t_mst == *fst)
        {
            mfN = mN;
            t_fst = fst;
            while(*t_mst == *t_fst && *t_fst)
            {
                t_mst++;
                t_fst++;
                mN++;
            }
                if (!*t_fst) break;
        }
        else
        {
            t_mst++;
            mN++;
        }
    if (*t_fst) return 0;
    while(*t_mst++) mN++;

    t_fst = fst;
    while(*t_fst++) fN++;
    while(*t_rst++) rN++;

    mN += (fN > rN) ? fN - rN : rN - fN;

    char temp[mN];

    for (int i = 0; i < mfN; i++) *(temp+i) = *(mst+i);
    for (int i = mfN; i < mfN+rN; i++) *(temp+i) = *( rst+(i-mfN) );
    for (int i = mfN+rN; i < mN; i++) *(temp+i) = *( mst+(i-rN+fN) );

    delete [] mst;

    mst = new char[mN];

    for (int i = 0; i < mN; i++) *(mst+i) = *(temp+i);

    return 1;
}


int main(int agrc, char** agrv)
{
    if (agrc != 3) { puts("Use: read_file.txt wright_file.txt"); return 0; }

    char* buf;

    FILE *in, *out;

    if ( (in = fopen(agrv[1], "rt")) == nullptr) { printf("Error! File \"%s\" not found!\n", agrv[1]); return 0; }
    if ( (out = fopen(agrv[2], "wt")) == nullptr) { printf("Error! File \"%s\" can not be created!\n", agrv[2]); return 0; }

    size_t fN = 0;
    while( !feof(in) )
    {
        size_t n = 0;
        char t_ch;
        while ( (t_ch = fgetc(in)) != '\n' && t_ch != EOF ) n++;
        n++;

        fseek(in, fN, SEEK_SET);
        fN += n;

        buf = new char[n+1];

        fgets(buf, n+1, in);

        //printf("|-->%s<--|\n", buf);    //xxx

        while( replace_word(buf, "ONE", " 1 ") );
        while( replace_word(buf, "TWO", " 2 ") );
        while( replace_word(buf, "THREE", " 3 ") );

        //printf("|-->%s<--|\n\n", buf);    //xxx

        fputs(buf, out);

        delete [] buf;
    }

    fclose(in);
    fclose(out);

    puts("Done!");

    return 0;
}
