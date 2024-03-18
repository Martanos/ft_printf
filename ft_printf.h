/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:31:43 by malee             #+#    #+#             */
/*   Updated: 2024/01/19 17:00:49 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *__format, ...);
int	print_format(char specifier, va_list ap);
int	print_digit(long long n, int base, char *symbols);
int	print_str(char *str);
int	print_char(int c);
int	print_pointer(unsigned long ptr);
int	parse_pointer(unsigned long ptr);

#endif