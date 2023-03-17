/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_orders_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:32:49 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack1, t_list **stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	ft_printf("rrr\n");
}
