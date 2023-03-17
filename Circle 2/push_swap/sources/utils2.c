/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:11:13 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:35:03 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last_node(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	move_b(t_list **a, t_list **b)
{
	t_list	*b_last;

	b_last = get_last_node(b);
	if ((*a)->value > b_last->value)
	{
		rrb(b);
		pb(b, a);
		rb(b);
	}
	else
		pb(b, a);
}

int	sorted_tab(int *table, int counts)
{
	int	i;

	i = 0;
	while (i < counts - 1)
	{
		if (table[i] > table[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int	tab_length(char *table)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(table, ' ');
	while (temp[i])
		i++;
	i++;
	return (i);
}
