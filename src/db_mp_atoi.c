#include "db_m_print.h"

int db_mp_atoi(void *buff)
{
    char *temp;
    int rst;

    rst = 0;
    temp = (char *)buff;
    while (*temp >= '0' && *temp <= '9')
    {
        rst = rst * 10;
        rst = rst + *temp - '0';
        temp++;
    }
    return rst;

}