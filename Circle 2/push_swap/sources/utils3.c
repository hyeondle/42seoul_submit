/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:47:30 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 18:34:42 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *table, int counts)
{
	int	i;
	int	n;

	i = 0;
	n = INT_MIN;
	while (i < counts)
	{
		if (table[i] > n)
			n = table[i];
		i++;
	}
	return (n);
}

int	find_min(int *table, int counts)
{
	int	i;
	int	n;

	i = 0;
	n = INT_MAX;
	while (i < counts)
	{
		if (table[i] < n)
			n = table[i];
		i++;
	}
	return (n);
}

void	changer(int flag, t_list **a, t_list **b)
{
	if (flag == 1)
	{
		ra(a);
		go_case_three(a, b);
		return ;
	}
	if (flag == 2)
	{
		ra(a);
		go_case_three(a, b);
		return ;
	}
}

void	free_stack(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		temp = (*a)->next;
		(*a)->value = 0;
		(*a)->next = NULL;
		free(*a);
		*a = temp;
	}
	*a = 0;
}
