#include "db_m_print.h"

void db_m_print(char *fmt, ...)
{
    int i;
    int count;
    int mode;
    char *fmt_ptr;
    void *temp;
    void *src;
    char *filename;
    t_file *file;
    int has_np;
    char *sep;
    int sep_len;
    int has_sep;
    int sep_malloc;
    va_list args;

    sep_malloc = 0;
    if (!(sep = db_mp_get_sep(fmt)))
        sep = SEPARATOR;
    else
        sep_malloc = 1;
    sep_len = db_mp_strlen(sep);
    if (db_mp_iz_in("-np", fmt))
        has_np = 1;
    if (db_mp_iz_in("-nosep", fmt))
        has_sep = 0;
    else
        has_sep = 1;
    if (filename = db_mp_get_filename(fmt))
    {
        if (!(file = db_mp_open_file(filename)))
            return ;
        src = file->buffer;
        mode = 'f';
    }
    else 
    {
        va_start(args, fmt);
        src = va_arg(args, void *);
        mode = 'b';
    }

    if (db_mp_iz_in("-np", fmt))
        has_np = 1;
    if (fmt_ptr = db_mp_iz_in("-i", fmt))
    {
        temp = src;
        i = 0;
        while (*fmt_ptr && *fmt_ptr == ' ')
            fmt_ptr++;
        if (!(count = db_mp_atoi(fmt_ptr)))
        {
            if (mode == 'f')
                count = file->size;
            else
                count = 1;
        }
        while (i < count)
        {
            db_mp_write_int(temp);
            temp = temp + 4;
            i++;
            if (i < count && has_sep == 1)
                write(1, sep, sep_len);
        }
    }

    if (fmt_ptr = db_mp_iz_in("-b", fmt))
    {
        temp = src;
        i = 0;
        while (*fmt_ptr && *fmt_ptr == ' ')
            fmt_ptr++;
        if (!(count = db_mp_atoi(fmt_ptr)))
        {
            if (mode == 'f')
                count = file->size;
            else
                count = 1;
        }
        while (i < count)
        {
            db_mp_write_byte(temp);
            temp = temp + 1;
            i++;
            if (i < count && has_sep == 1)
                write(1, sep, sep_len);
        }
    }

    if (fmt_ptr = db_mp_iz_in("-c", fmt))
    {
        temp = src;
        i = 0;
        while (*fmt_ptr && *fmt_ptr == ' ')
            fmt_ptr++;
        if (!(count = db_mp_atoi(fmt_ptr)))
        {
            if (mode == 'f')
                count = file->size;
            else
                count = 1;
        }
        while (i < count)
        {
            db_mp_write_char(temp, has_np);
            temp = temp + 1;
            i++;
            if (i < count && has_sep == 1)
                write(1, sep, sep_len);
        }
    }
    if (fmt_ptr = db_mp_iz_in("-s", fmt))
    {
        temp = src;
        i = 0;
        while (*fmt_ptr && *fmt_ptr == ' ')
            fmt_ptr++;
        if (!(count = db_mp_atoi(fmt_ptr)))
        {
            if (mode == 'f')
                count = file->size;
            else
                count = db_mp_strlen((char *)temp);
        }
        while (i < count)
        {
            db_mp_write_char(temp, has_np);
            temp = temp + 1;
            i++;
            if (i < count && has_sep == 1)
                write(1, sep, sep_len);
        }
    }
    write(1, "\n", 1);

    if (mode == 'f')
    {
        free(file->buffer);
        free(file);
        free(filename);
    }

    if (sep_malloc == 1)
        free(sep);
}