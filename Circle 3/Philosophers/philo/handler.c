/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 02:22:37 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:18 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printerror(int e_type)
{
	if (e_type == 1)
	{
		printf("Invalid Inputs\n");
		printf("Usage : number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
	}
	else if (e_type == 2)
	{
		printf("Invalid Inputs\n");
		printf("Inputs must be positive decimals\n");
	}
	else if (e_type == 3)
	{
		printf("Allocate Error Occured\n");
	}
}

int	input_check(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printerror(1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0 || decimal_checker(argv[i]) < 0)
		{
			printerror(2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	decimal_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}
