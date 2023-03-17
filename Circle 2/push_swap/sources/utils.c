/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:23:54 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:59:09 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goterror(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	find_n(int *table, char orders, int counts)
{
	int	i;
	int	n;

	i = 0;
	if (orders == 'M')
	{
		n = find_max(table, counts);
		return (n);
	}
	else if (orders == 'm')
	{
		n = find_min(table, counts);
		return (n);
	}
	else
		goterror();
	return (0);
}

void	swap_tab(int **table, int index)
{
	int	temp;

	temp = (*table)[index];
	(*table)[index] = (*table)[index + 1];
	(*table)[index + 1] = temp;
}

static int	ft_space_count(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
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
			goterror();
		else if (ft_result * is_negative < -2147483648)
			goterror();
	}
	return ((int)ft_result * is_negative);
}
