#include <stdlib.h>

char *ft_itoa(int n)
{
    char *result;
    int len;
    int n_cpy;
    int minus;

    n_cpy = n;
    len = 0;
    minus = 1;

    if (n < 0)
    {
        len++;
        minus *= -1;
    }
    if (n == 0)
        len++;
    while(n_cpy)
    {
        len++;
        n_cpy /= 10;
    }
    result = malloc (len + 1);
    result[len] = '\0';
    while (--len >= 0)
    {
        if (minus > 0)
            result[len] = n % 10 + '0';
        else
            result[len] = - (n % 10) + '0';
        n /= 10;
    }
    if (minus == -1)
        result[0] = '-';
    return (result);
}