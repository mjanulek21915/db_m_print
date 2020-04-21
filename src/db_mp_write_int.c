#include "db_m_print.h"

void db_mp_write_int(void *buff)
{
    int temp;

    temp = *((int *)buff);
    db_mp_write_put_base(temp, BASE10);
}