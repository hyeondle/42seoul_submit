/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:15:17 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:54:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (-1);
		else if (ft_result * is_negative < -2147483648)
			return (0);
	}
	return (ft_result * is_negative);
}
