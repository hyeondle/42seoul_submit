/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:28:03 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/18 18:10:31 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_int(va_list conv, int type)
{
	int				printed_leng;
	unsigned int	num;

	if (type == 8)
	{
		num = (unsigned int)va_arg(conv, int);
		printed_leng = ft_putnbr_base(num, "0123456789abcdef");
	}
	else if (type == 9)
	{
		num = (unsigned int)va_arg(conv, int);
		printed_leng = ft_putnbr_base(num, "0123456789ABCDEF");
	}
	else
	{
		num = va_arg(conv, unsigned int);
		if (num < 0)
			num *= -1;
		printed_leng = ft_putnbr(num, 0);
	}
	return (printed_leng);
}
