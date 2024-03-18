/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:31:43 by malee             #+#    #+#             */
/*   Updated: 2024/01/19 17:00:03 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	size_t	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10,
				"0123456789");
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)),
				16, "0123456789abcdef");
	else if (specifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)),
				16, "0123456789ABCDEF");
	else if (specifier == 'p')
		count += parse_pointer(va_arg(ap, unsigned long));
	else if (specifier == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)),
				10, "0123456789");
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
