/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:55 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_decimal(va_list conv)
{
	int	num_length;
	int	num;

	num = (long long)va_arg(conv, int);
	num_length = ft_putnbr_fd(num, 0);
	return (num_length);
}
