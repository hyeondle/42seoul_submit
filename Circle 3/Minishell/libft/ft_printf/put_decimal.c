/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:55 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/18 18:10:31 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_decimal(va_list conv)
{
	int	num_length;
	int	num;

	num = (long long)va_arg(conv, int);
	num_length = ft_putnbr(num, 0);
	return (num_length);
}
