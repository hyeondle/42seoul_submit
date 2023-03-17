/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:38:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 19:20:17 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*sec;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	sec = (*stack)->next;
	(*stack)->next = sec->next;
	sec->next = *stack;
	*stack = sec;
}

// first value is order's destination. ex) pa = push(&a, &b)
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*value;

	if (*stack_src == NULL)
		return ;
	value = *stack_src;
	if ((*stack_src)->next == NULL)
		*stack_src = NULL;
	else
		*stack_src = (*stack_src)->next;
	value->next = *stack_dst;
	*stack_dst = value;
}

void	rotate(t_list **stack)
{
	t_list	*stack_f;
	t_list	*stack_s;
	t_list	*stack_temp;

	stack_f = *stack;
	stack_s = (*stack)->next;
	stack_temp = stack_s;
	stack_f->next = NULL;
	while (stack_temp->next != NULL)
		stack_temp = stack_temp->next;
	stack_temp->next = stack_f;
	*stack = stack_s;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*stack_f;
	t_list	*stack_e;
	t_list	*stack_temp;

	stack_f = *stack;
	stack_temp = *stack;
	stack_e = *stack;
	while (stack_temp->next != NULL)
		stack_temp = stack_temp->next;
	while (stack_e->next != stack_temp)
		stack_e = stack_e->next;
	stack_e->next = NULL;
	stack_temp->next = stack_f;
	*stack = stack_temp;
}
