#include <stdio.h>
#include <ctype.h>

#include "student.h"

void showStudentInfo(const Student &s, int new_line)
{
    printf("%-20s\t%s\t%d\t%d %d %d %d %d",
                                                    s.name,
                                                    s.group,
                                                    s.year,
                                                    s.marks[0],
                                                    s.marks[1],
                                                    s.marks[2],
                                                    s.marks[3],
                                                    s.marks[4]
                                                );
    while(new_line--) putchar('\n');
}

float getAverMarks(const Student &s)
{
    float t = 0.f;
    for (int i = 0; i < 5; i++) t += s.marks[i];
    t /= 5;
    return t;
}

bool compByName(const Student &s1, const Student &s2)
{
    const char *st1 = s1.name, *st2 = s2.name;
    while(*st1 && *st2)
    {
        if(toupper(*st1)-toupper(*st2) > 0) return 1;
        if (toupper(*st1)-toupper(*st2) < 0) return 0;
        st1++;
        st2++;
    }
    return 0;
}

bool compByGroup(const Student &s1, const Student &s2)
{
    const char *st1 = s1.group, *st2 = s2.group;
    while(*st1 && *st2)
    {
        if(toupper(*st1)-toupper(*st2) > 0) return 1;
        if (toupper(*st1)-toupper(*st2) < 0) return 0;
        st1++;
        st2++;
    }
    return 0;
}

bool compByYear(const Student &s1, const Student &s2)
{
    return (s1.year < s2.year) ? 1 : 0;
}

bool compByAverMarks(const Student &s1, const Student &s2)
{
    return (getAverMarks(s1) > getAverMarks(s2)) ? 1 : 0;
}

void sortDB(Student *db, int N, bool (*comp)(const Student&, const Student&))
{
     for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++)
            if (comp(db[i], db[j]))
            {
                Student t = db[i];
                db[i] = db[j];
                db[j] = t;
            }
}

