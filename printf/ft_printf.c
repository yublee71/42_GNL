#include "ft_printf.h"

void	whatistype(char c, va_list args)
{
	if (c == 'c')
	else if (c == 's')
	else if (c == 'p')
	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')
	else
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
			whatistype(format[i + 1], args);
	}
	va_end(args);
}