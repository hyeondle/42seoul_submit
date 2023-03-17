/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:07 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:55:36 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_v2(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n <= 9)
	{
		ft_putchar_v2(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_v2(n % 10, fd);
	}
}
