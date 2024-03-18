/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:50:55 by malee             #+#    #+#             */
/*   Updated: 2024/01/19 17:01:01 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	if (!str)
		return (print_str("(null)"));
	count = 0;
	while (*str)
	{
		print_char(*str);
		++count;
		++str;
	}
	return (count);
}

int	print_digit(long long n, int base, char *symbols)
{
	int		count;

	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base, symbols) + 1);
	}
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base, symbols);
		return (count + print_digit(n % base, base, symbols));
	}
}

int	print_pointer(unsigned long ptr)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (ptr > 15)
		count += print_pointer(ptr / 16);
	count += print_char(base[ptr % 16]);
	return (count);
}

int	parse_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += print_str("(nil)");
	else
	{
		count += print_str("0x");
		count += print_pointer(ptr);
	}
	return (count);
}
