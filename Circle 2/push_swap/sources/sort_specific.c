/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:46:01 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:31:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_list **a, t_list **b, int count, t_piv piv)
{
	int	work;
	int	done;

	done = 0;
	while (done + 1 < piv.task)
	{
		work = 0;
		while (work < count / piv.task)
		{
			if ((*a)->value <= piv.piv[done])
			{
				pb(b, a);
				work++;
			}
			else
				ra(a);
		}
		done++;
	}
}

void	move_leftone(t_list **a, t_list **b)
{
	while ((*a)->next != NULL)
		move_b(a, b);
	pa(a, b);
	pa(a, b);
	sort_under_3(a);
}

static void	sort_under_3_each_case(int cased, t_list **a)
{
	if (cased == 1)
	{
		sa(a);
		ra(a);
	}
	else if (cased == 2)
		sa(a);
	else if (cased == 3)
		rra(a);
	else if (cased == 4)
		ra(a);
	else if (cased == 5)
	{
		sa(a);
		rra(a);
	}
}

static int	get_case(int f, int s, int t)
{
	if (f < s && f < t && s > t)
		return (1);
	else if (f > s && f < t)
		return (2);
	else if (f < s && f > t)
		return (3);
	else if (f > s && f > t)
	{
		if (s < t)
			return (4);
		else if (s > t)
			return (5);
	}
	return (-1);
}

void	sort_under_3(t_list **a)
{
	t_list	*temp;
	int		f;
	int		s;
	int		t;
	int		cased;

	f = (*a)->value;
	temp = (*a)->next;
	s = temp->value;
	temp = temp->next;
	t = temp->value;
	cased = get_case(f, s, t);
	if (cased == -1)
		return ;
	else
		sort_under_3_each_case(cased, a);
}
