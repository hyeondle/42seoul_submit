/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:01 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:59:32 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_num_to_str(char *str, long num, int i);

static int	length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;

	num = (long)n;
	i = length(num);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str = put_num_to_str(str, num, i);
	return (str);
}

static char	*put_num_to_str(char *str, long num, int i)
{
	while (num > 0)
	{
		i--;
		str[i] = 48 + (num % 10);
		num /= 10;
	}
	return (str);
}
