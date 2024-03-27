/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:31:43 by malee             #+#    #+#             */
/*   Updated: 2024/03/27 16:06:07 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_conversion_handlers
{
	char	specifier;
	ssize_t	(*handler)(va_list * args);
}			t_conversion_handlers;

int			ft_printf(const char *__format, ...);
ssize_t		handle_digit(size_t n, int base, const char *symbols,
				int is_signed);
ssize_t		handle_string(va_list *args);
ssize_t		handle_char(va_list *args);
ssize_t		handle_upper_hex(va_list *args);
ssize_t		handle_lower_hex(va_list *args);
ssize_t		handle_int(va_list *args);
ssize_t		handle_uint(va_list *args);
ssize_t		handle_pointer(va_list *args);

#endif