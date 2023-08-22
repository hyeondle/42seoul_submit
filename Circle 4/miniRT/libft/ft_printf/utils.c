/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:28:46 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/18 18:10:30 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fp_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static int	ft_putchar_v2(int n, int d)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
	d++;
	return (d);
}

int	ft_putnbr(long long n, int printed_num)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		printed_num++;
		printed_num = ft_putnbr(n, printed_num);
	}
	else if (n <= 9)
	{
		printed_num = ft_putchar_v2(n, printed_num);
	}
	else
	{
		printed_num = ft_putnbr(n / 10, printed_num);
		printed_num = ft_putchar_v2(n % 10, printed_num);
	}
	return (printed_num);
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	printed_num;

	printed_num = 0;
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		printed_num += ft_putnbr_base(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	printed_num++;
	return (printed_num);
}
