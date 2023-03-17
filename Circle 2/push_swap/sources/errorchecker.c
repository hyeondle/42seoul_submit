/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:48:10 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:17:32 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(int *table, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (table[j] == table[i])
				goterror();
			j++;
		}
		i++;
	}
}

static void	check_sorted(int *table, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (table[i] > table[i + 1])
			break ;
		i++;
	}
	if (i == argc - 2)
		exit(1);
}

void	check_table(int *table, int argc)
{
	check_duplicate(table, argc);
	check_sorted(table, argc);
}
