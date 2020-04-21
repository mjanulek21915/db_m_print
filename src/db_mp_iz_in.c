#include "db_m_print.h"

char *db_mp_iz_in(char *needl, char *hayst)
{
    int i;
    int j;

    i = 0;
    while (hayst[i])
    {
        j = 0;
        while (hayst[i + j] == needl[j])
        {
            j++;
            if (needl[j] == 0)
                return (hayst + i + j);
        }
        i++;
    }
    return (NULL);
}