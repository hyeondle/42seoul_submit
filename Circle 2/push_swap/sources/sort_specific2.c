/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:09:03 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 18:29:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_list **a, t_list **b, int **table, int argc)
{
	int		nmax;
	int		nmin;
	int		flag;
	t_list	*temp;

	nmax = find_n(*table, 'M', argc - 1);
	nmin = find_n(*table, 'm', argc - 1);
	flag = 0;
	while (flag < 1)
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
	temp = (*a)->next;
	if (temp->value < (*a)->value)
		ra(a);
}
