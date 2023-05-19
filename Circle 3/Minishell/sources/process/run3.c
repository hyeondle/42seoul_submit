/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:05:11 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/06 03:14:28 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/minishell.h"

void	free_deque(t_deque *deque)
{
	t_node	*node;
	t_node	*next_node;

	node = deque->front;
	while (node)
	{
		next_node = node->next;
		free_2d_array(node->cmd);
		free_2d_array(node->order_redir);
		free_2d_array(node->file_redir);
		free_2d_array(node->filename_heredoc);
		free(node);
		node = next_node;
	}
	free(deque);
}

void	free_run_cmd(t_deque *deque, t_info *info, t_heredoc *hdoc)
{
	int	i;

	free_deque(deque);
	i = 0;
	while (i < info->num_pipe)
	{
		free(info->pipes[i]);
		i++;
	}
	free(info->pipes);
	free(info->arr_pid);
	free(info);
	free_2d_array(hdoc->terminators);
	free_2d_array(hdoc->filename_temp);
	free(hdoc->fd_heredoc);
	free(hdoc);
}

void	run_cmd_fork(t_deque *deque, t_info *info, char **envp, t_setting **set)
{
	t_node	*node;

	node = deque->front;
	while (node)
	{
		info->arr_pid[node->idx] = fork();
		if (info->arr_pid[node->idx] < 0)
			ft_p_error("Error: fork()");
		else if (info->arr_pid[node->idx] == 0)
		{
			ft_signal_child();
			child_process(node, info, envp, set);
		}
		else
		{
			ignores();
			node = parent_process(node, info);
		}
	}
}
