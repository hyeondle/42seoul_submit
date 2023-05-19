/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:48 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 10:44:37 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	init_node(t_node *node)
{
	init_2d_arr(&(node->cmd));
	init_2d_arr(&(node->order_redir));
	init_2d_arr(&(node->file_redir));
	init_2d_arr(&(node->filename_heredoc));
	node->num_heredoc = 0;
}

t_node	*push_init_new_node(t_deque *deque)
{
	t_node	*node;

	node = new_node();
	init_node(node);
	push_r(deque, node);
	return (node);
}
