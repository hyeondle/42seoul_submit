/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:34:58 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	c_per_type(char char_first, char char_second);
static int	w_per_type(va_list conv, int type);

int	ft_printf(const char *str_m, ...)
{
	int		printed_num;
	int		i;
	va_list	conv;

	i = 0;
	printed_num = 0;
	va_start(conv, str_m);
	while (str_m[i] != '\0')
	{
		if (c_per_type(str_m[i], str_m[i + 1]) == -1)
			return (0);
		else if (c_per_type(str_m[i], str_m[i + 1]) == 0)
		{
			write(1, &str_m[i], 1);
			printed_num++;
		}
		else
		{
			printed_num += w_per_type(conv, c_per_type(str_m[i], str_m[i + 1]));
			i++;
		}
		i++;
	}
	va_end(conv);
	return (printed_num);
}

static int	c_per_type(char char_first, char char_second)
{
	if (char_first != '%')
		return (0);
	if (char_first == '%')
	{
		if (char_second == '%')
			return (1);
		else if (char_second == 'c')
			return (2);
		else if (char_second == 's')
			return (3);
		else if (char_second == 'p')
			return (4);
		else if (char_second == 'd')
			return (5);
		else if (char_second == 'i')
			return (6);
		else if (char_second == 'u')
			return (7);
		else if (char_second == 'x')
			return (8);
		else if (char_second == 'X')
			return (9);
	}
	return (-1);
}

static int	w_per_type(va_list conv, int type)
{
	int	printed_num;

	printed_num = 0;
	if (type == 1)
	{
		write(1, "%", 1);
		return (1);
	}
	else if (type == 2)
		printed_num = put_char(conv);
	else if (type == 3)
		printed_num = put_string(conv);
	else if (type == 4)
		printed_num = put_void_pointer(conv);
	else if (type == 5 || type == 6)
		printed_num = put_decimal(conv);
	else if (type == 7 || type == 8 || type == 9)
		printed_num = put_unsigned_int(conv, type);
	return (printed_num);
}
