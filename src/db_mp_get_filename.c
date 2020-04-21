#include "db_m_print.h"

int static db_mp_get_len(char *ptr)
{
    int i;

    i = 0;
    while (ptr[i] && ptr[i] != '$')
        i++;
    if (ptr[i] == '$')
        return (i);
    return 0;
    
}

void static db_mp_strncpy(char *src, char *dest, int size)
{
    while (size--)
        *dest++ = *src++;
    *dest = 0;
}

char *db_mp_get_filename(char *fmt)
{
    int len;
    char *rst;

    while (*fmt && *fmt != '$')
        fmt++;

    if (!(*fmt))
    {
        fprintf(stderr, "no filename\n");
        return (NULL);
    }

    fmt = fmt + 1;

    if (!(len = db_mp_get_len(fmt)))
    {
        fprintf(stderr, "invalid filename format\n");
        return (NULL);
    }

    if (!(rst = malloc(sizeof(char) * (len + 1))))
    {
        fprintf(stderr, "dp_mp_get_filename malloc fail\n");
        return NULL;
    }

    db_mp_strncpy(fmt, rst, len);
    return (rst);
}