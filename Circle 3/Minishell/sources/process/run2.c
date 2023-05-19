/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:53 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/12 12:58:47 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/minishell.h"

void	check_pipe_redir(t_node *node, t_info *info)
{
	int	i;

	if (node->prev)
		dup2(info->pipes[node->idx - 1][READ], STDIN_FILENO);
	if (node->next)
		dup2(info->pipes[node->idx][WRITE], STDOUT_FILENO);
	i = 0;
	while (i < info->num_pipe)
	{
		close(info->pipes[i][READ]);
		close(info->pipes[i][WRITE]);
		i++;
	}
}

void	check_file_redir(t_node *node)
{
	int	idx_hd_in_node;
	int	i;

	if (node->order_redir)
	{
		idx_hd_in_node = 0;
		i = 0;
		while (node->order_redir[i])
		{
			if (ft_strcmp(node->order_redir[i], "<") == 0)
				redir_infile(node, i);
			if (ft_strcmp(node->order_redir[i], ">") == 0)
				redir_outfile_ow(node, i);
			if (ft_strcmp(node->order_redir[i], ">>") == 0)
				redir_outfile_apd(node, i);
			if (ft_strcmp(node->order_redir[i], "<<") == 0)
				redir_heredoc(node, idx_hd_in_node++);
			i++;
		}
	}
}

void	child_process(t_node *node, t_info *info, char **envp, t_setting **set)
{
	check_pipe_redir(node, info);
	check_file_redir(node);
	if (node->cmd)
		exec(node->cmd, envp, set);
	exit(0);
}

t_node	*parent_process(t_node *node, t_info *info)
{
	if (node->prev)
	{
		close(info->pipes[node->idx - 1][READ]);
		info->pipes[node->idx - 1][READ] = -1;
	}
	if (node->next)
	{
		close(info->pipes[node->idx][WRITE]);
		info->pipes[node->idx][WRITE] = -1;
	}
	return (node->next);
}

int	ft_wait_pids(t_info *info, t_setting **set)
{
	int	i;
	int	status;

	i = 0;
	while (i < (info->num_pipe + 1))
	{
		waitpid(info->arr_pid[i], &status, 0);
		if (WIFEXITED(status))
		{
			(*set)->last_exit_status = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			(*set)->last_exit_status = WTERMSIG(status);
		}
		i++;
	}
	return ((*set)->last_exit_status);
}
