/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:55:37 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:06:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_number_base(char c, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if ("0123456789abcdef"[i] == c || "0123456789ABCDEF"[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_space_count(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_isnumber(char *str, int base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (ft_space_count(str))
		i = i + ft_space_count(str);
	if (base != 10 && !(str[i] == '0' && str[i + 1] == 'x'))
		return (0);
	if (base == 16)
	{
		i = i + 2;
		sign = 1;
	}
	if (base == 10 && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i = i + 1;
	}
	while (ft_number_base(str[i], base) >= 0)
		result = result * base + ft_number_base(str[i++], base);
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int			is_negative;
	int			space_count;
	long long	ft_result;
	int			i;

	ft_result = 0;
	is_negative = 1;
	space_count = ft_space_count((char *)str);
	i = space_count;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_result = ft_result * 10 + str[i] - '0';
		i++;
		if (ft_result * is_negative > 2147483647)
			return (-1);
		else if (ft_result * is_negative < -2147483648)
			return (0);
	}
	return ((int)(ft_result * is_negative));
}
