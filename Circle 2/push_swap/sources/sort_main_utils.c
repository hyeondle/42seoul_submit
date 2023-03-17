/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:19 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 20:00:48 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_and_down(t_list **stack, int num)
{
	t_list	*temp;
	int		count;

	temp = *stack;
	count = 0;
	while (temp->value != num)
	{
		temp = temp->next;
		count++;
	}
	while (temp)
	{
		temp = temp->next;
		count--;
	}
	if (count < 0)
		return (1);
	else
		return (2);
	return (-1);
}

int	get_case_g(t_list **b, int a_max, int a_min)
{
	if ((*b)->value < a_min)
		return (1);
	else if ((*b)->value > a_max)
		return (2);
	else if ((*b)->value > a_min && (*b)->value < a_max)
		return (3);
	return (-1);
}

int	find_num(t_list **stack, char order)
{
	t_list	*temp;
	int		value;

	temp = *stack;
	value = INT_MIN;
	if (order == 'M')
	{
		while (temp)
		{
			if (temp->value > value)
				value = temp->value;
			temp = temp->next;
		}
	}
	else if (order == 'm')
	{
		value = INT_MAX;
		while (temp)
		{
			if (temp->value < value)
				value = temp->value;
			temp = temp->next;
		}
	}
	return (value);
}

int	find_middle_num(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a)->next;
	while (temp->next != NULL)
	{
		if (temp->value < (*a)->value && temp->value > (*b)->value)
			return (1);
		else
			temp = temp->next;
	}
	temp = (*a)->next;
	while (temp->next != NULL)
	{
		if (temp->value < (*a)->value && temp->value > (*b)->value)
		{
			return (2);
		}
		else
			temp = temp->next;
	}
	return (0);
}

void	ordering(t_list **a, int value)
{
	while ((*a)->value != value)
		ra(a);
}
