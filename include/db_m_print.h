#ifndef __DB_M_PRINT_H__
#define __DB_M_PRINT_H__

#define BASE10 "0123456789"
#define SEPARATOR "|"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

typedef struct  s_file
{
    void *buffer;
    int size;
}               t_file;

void db_mp_test();
void db_mp_test2();
char *db_mp_iz_in(char *needl, char *hayst);
int	db_mp_strlen(char *str);
void db_mp_write_int(void *buff);
void	db_mp_write_put_base(long long n, char *base);
void db_m_print(void *buff, char *fmt);
int db_mp_atoi(void *buff);
char *db_mp_get_filename(char *fmt);
t_file *db_mp_open_file(char *path);
void db_mp_write_byte(void *buff);
void db_mp_write_char(void *buff, int mode);
char *db_mp_get_sep(char *fmt);

#endif