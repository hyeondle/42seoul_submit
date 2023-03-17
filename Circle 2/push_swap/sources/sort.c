/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:00:39 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 18:25:36 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **a, t_list **b, int **table, int count)
{
	t_piv	piv;
	int		i;

	sort_table(table, count);
	if (count < 300)
		piv.task = 6;
	else
		piv.task = 15;
	piv.piv = (int *)malloc(sizeof(int) * piv.task);
	i = 0;
	while (i < piv.task)
	{
		piv.piv[i] = (*table)[count / piv.task * (i + 1)];
		i++;
	}
	move_a_to_b(a, b, count, piv);
	move_leftone(a, b);
	rrb(b);
	free(piv.piv);
	go_greedy(a, b);
}

static void	sort_2(t_list **a)
{
	t_list	*temp;

	temp = (*a)->next;
	if (temp->value < (*a)->value)
		ra(a);
}

static void	sort_5(t_list **a, t_list **b, int **table, int argc)
{
	int		nmax;
	int		nmin;
	int		flag;
	t_list	*temp;

	nmax = find_n(*table, 'M', argc - 1);
	nmin = find_n(*table, 'm', argc - 1);
	flag = 0;
	while (flag < 2)
	{
		if ((*a)->value == nmax || (*a)->value == nmin)
		{
			flag++;
			pb(b, a);
		}
		else
			ra(a);
	}
	sort_under_3(a);
	pa(a, b);
	pa(a, b);
	temp = (*a)->next;
	if (temp->value > (*a)->value)
		sa(a);
	ra(a);
}

void	find_case_and_sort(int argc, t_list **a, t_list **b, int **table)
{
	if (argc == 3)
		sort_2(a);
	else if (argc == 4)
		sort_under_3(a);
	else if (argc == 5)
		sort_4(a, b, table, argc);
	else if (argc == 6)
		sort_5(a, b, table, argc);
	else
		sort(a, b, table, argc - 1);
}

void	sort_table(int **table, int counts)
{
	int	i;
	int	flag;

	flag = 0;
	while (flag != 1)
	{
		i = 0;
		while (i < counts - 1)
		{
			if ((*table)[i] > (*table)[i + 1])
				swap_tab(table, i);
			i++;
		}
		flag = sorted_tab(*table, counts);
	}
}
