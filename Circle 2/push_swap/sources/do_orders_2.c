/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_orders_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:22:32 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:30 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rr(t_list **stack1, t_list **stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_printf("rr\n");
}
