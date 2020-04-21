#include "db_m_print.h"

int static			db_mp_put_base_recursive(long long n, char *base, int len_base)
{
	long long temp;
	int i;

	i = 0;
	temp = n % len_base;
	if (n > len_base - 1)
		i += db_mp_put_base_recursive(n / len_base, base, len_base);
	// fprintf(stderr, "%lld, ", temp);
	write(1, &(base[temp]), 1);
	return (i + 1);
}

void				db_mp_write_put_base(long long n, char *base)
{
	int len_base;

	len_base = db_mp_strlen(base);
	if (n == LONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	db_mp_put_base_recursive(n, base, len_base);
}