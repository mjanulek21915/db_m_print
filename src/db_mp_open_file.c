#include "db_m_print.h"

int static db_mp_get_len(char *path)
{
    int fd;
    int dump;
    int rst;
    int status;

    rst = 0;
    fd = open(path, O_RDONLY);
    while (read(fd, &dump, 1))
        rst++;
    close(fd);
    return (rst);
}

t_file *db_mp_open_file(char *path)
{
    t_file *rst;
    int len;
    int fd;

    len = db_mp_get_len(path);

    if (!(len))
    {
        fprintf(stderr, "file is empty\n");
        return (NULL);
    }

    if (!(rst = malloc(sizeof(t_file))) || !(rst->buffer = malloc(sizeof(char) * len)))
    {
        fprintf(stderr, "db_mp_open_file malloc fail\n");
        return (NULL);
    }

    rst->size = len;
    fd = open(path, O_RDONLY);
    read(fd, rst->buffer, len);
    close(fd);
    return (rst);
}