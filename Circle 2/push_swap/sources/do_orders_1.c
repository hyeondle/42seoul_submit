/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_orders_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:22:23 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:07 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stack1, t_list **stack2)
{
	swap(stack1);
	swap(stack2);
	ft_printf("ss\n");
}

void	pa(t_list **stack_dst, t_list **stack_src)
{
	push(stack_dst, stack_src);
	ft_printf("pa\n");
}

void	pb(t_list **stack_dst, t_list **stack_src)
{
	push(stack_dst, stack_src);
	ft_printf("pb\n");
}
