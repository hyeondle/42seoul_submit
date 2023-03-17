/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:38:54 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:58:01 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_case_one(t_list **a, t_list **b, int value)
{
	int	u_a_d;

	u_a_d = up_and_down(a, value);
	if (u_a_d == 1)
	{
		while ((*a)->value != value)
			ra(a);
		pa(a, b);
	}
	else if (u_a_d == 2)
	{
		while ((*a)->value != value)
			rra(a);
		pa(a, b);
	}
}

void	go_case_two(t_list **a, t_list **b, int value)
{
	int	u_a_d;

	u_a_d = up_and_down(a, value);
	if (u_a_d == 1)
	{
		while ((*a)->value != value)
			ra(a);
		ra(a);
		pa(a, b);
	}
	else if (u_a_d == 2)
	{
		while ((*a)->value != value)
			rra(a);
		ra(a);
		pa(a, b);
	}
}

void	go_case_three(t_list **a, t_list **b)
{
	int		flag;
	t_list	*temp;

	flag = 0;
	while ((*b)->value > (*a)->value)
		ra(a);
	temp = get_last_node(a);
	while (temp->value > (*b)->value)
	{
		rra(a);
		temp = get_last_node(a);
		return ;
	}
	flag = find_middle_num(a, b);
	changer(flag, a, b);
	pa(a, b);
}

static void	sort_by_case(t_list **a, t_list **b, int case_g)
{
	int	a_max;
	int	a_min;
	int	flag;

	a_max = 0;
	a_min = 0;
	flag = 0;
	if (case_g == 1)
		go_case_one(a, b, find_num(a, 'm'));
	else if (case_g == 2)
		go_case_two(a, b, find_num(a, 'M'));
	else if (case_g == 3)
		go_case_three(a, b);
}

void	go_greedy(t_list **a, t_list **b)
{
	int	case_g;

	case_g = 0;
	while ((*b))
	{
		case_g = get_case_g(b, find_num(a, 'M'), find_num(a, 'm'));
		sort_by_case(a, b, case_g);
	}
	ordering(a, find_num(a, 'm'));
}
