#include <stdio.h>
#include <ctype.h>
#include "conio.h"
#include "student.h"

int main()
{
    const char* dir = "db.txt";

    Student* db;
    int N = 0;

    FILE* f;

    if ( (f = fopen(dir, "rt")) == nullptr) puts("Error! File not found!\n");
    else
    {
        char temp[256];
        for(; !feof(f); N++) fgets(temp, sizeof(temp), f);
        rewind(f);

        db = new Student[N];

        for (int i = 0; i < N; i++)
        {
            fscanf(f, "%s %s %d %d %d %d %d %d",
                                                    db[i].name,
                                                    db[i].group,
                                                    &db[i].year,
                                                    db[i].marks,
                                                    db[i].marks+1,
                                                    db[i].marks+2,
                                                    db[i].marks+3,
                                                    db[i].marks+4
                                                );
        }
         fclose(f);

         bool fO = 1;
         while(fO)
         {
            printf("Choose type of sorting:\nN - by name\nG - by group\nY - by year\nA - by average mark\nESC - to exit\n");

            bool fI = 1;
            while(fI)
                switch (toupper(getch()) )
                {
                    case 'N':
                    {
                        puts("N\n\n");
                        sortDB(db, N, compByName);
                        fI = 0;
                    } break;

                    case 'G':
                    {
                        puts("G\n\n");
                        sortDB(db, N, compByGroup);
                        fI = 0;
                    } break;

                    case 'Y':
                    {
                        puts("Y\n\n");
                        sortDB(db, N, compByYear);
                        fI = 0;
                    } break;

                    case 'A':
                    {
                        puts("A\n\n");
                        sortDB(db, N, compByAverMarks);
                        fI = 0;
                    } break;

                    case 27:
                    {
                        fO = fI = 0;
                    } break;

                    default: continue;
                }

                if (fO)
                {
                    for (int i = 0; i < N; i++) showStudentInfo(db[i], 1);
                    puts("\n\n");
                }
         }

         delete [] db;
    }

    return 0;
}
