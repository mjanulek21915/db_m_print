#include <stdarg.h>
#include "db_m_print.h"

void fonction(char *fmt, ...)
{
    va_list args;
    char *temp;

    if (db_mp_iz_in("$", fmt))
    {
        va_start(args, fmt);
        temp = va_arg(args, char *);
        printf("%s\n", temp);
    }
    else
        printf("zebe\n");
}

int main()
{
    char test[100] = "cesi est un tsring";
    fonction("hahahha$", test);
}