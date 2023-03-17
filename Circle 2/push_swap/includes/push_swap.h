/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:28:59 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 18:30:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_counts
{
	int	count;
	int	up_or_down;
}		t_counts;

typedef struct s_piv
{
	int	task;
	int	*piv;
}		t_piv;

int		find_middle_num(t_list **a, t_list **b);
int		get_case_g(t_list **b, int a_max, int a_min);
int		find_num(t_list **stack, char order);
int		up_and_down(t_list **stack, int num);

void	go_greedy(t_list **a, t_list **b);
void	sort_4(t_list **a, t_list **b, int **table, int argc);
void	find_case_and_sort(int argc, t_list **a, t_list **b, int **table);
void	sort_under_3(t_list **a);
void	sort_table(int **table, int counts);
void	go_case_three(t_list **a, t_list **b);
void	move_a_to_b(t_list **a, t_list **b, int count, t_piv piv);
void	move_b(t_list **a, t_list **b);
void	move_leftone(t_list **a, t_list **b);

int		*make_table_with_split(char **argv);
int		*make_table(int argc, char **argv);
t_list	*make_stack(int *table, t_list *b_stack, int argc);
void	changer(int flag, t_list **a, t_list **b);

void	check_table(int *table, int argc);
int		find_min(int *table, int counts);
int		find_max(int *table, int counts);
void	ordering(t_list **a, int value);
void	goterror(void);
int		ft_atoi(const char *str);
int		find_n(int *table, char orders, int counts);
void	swap_tab(int **table, int index);
t_list	*get_last_node(t_list **stack);
int		sorted_tab(int *table, int counts);
int		tab_length(char *table);
void	free_stack(t_list **a);
// orders.c //
void	swap(t_list **stack);
void	push(t_list **stack_dst, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
// do_orders*.c //
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack1, t_list **stack2);
void	pa(t_list **stack_dst, t_list **stack_src);
void	pb(t_list **stack_dst, t_list **stack_src);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack1, t_list **stack2);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack1, t_list **stack2);

#endif