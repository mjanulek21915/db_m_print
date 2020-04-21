#include "db_m_print.h"

void db_mp_write_byte(void *buff)
{
    int temp;

    temp = *((unsigned char *)buff);
    db_mp_write_put_base(temp, BASE10);
}