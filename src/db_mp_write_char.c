#include "db_m_print.h"

void db_mp_write_char(void *buff, int mode)
{
    unsigned char *temp;

    temp = (unsigned char *)buff;
    if (mode == 1 && *temp < 32 || *temp > 126)
    {
        write(1, "/", 1);
        db_mp_write_put_base(*temp, BASE10);
    }
    else
        write (1, temp, 1);
}