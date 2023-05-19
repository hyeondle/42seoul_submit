/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:52 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 03:14:43 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/minishell.h"

void	unlink_temp_file(t_heredoc *hdoc)
{
	int	i;

	i = 0;
	while (hdoc->filename_temp[i])
	{
		unlink(hdoc->filename_temp[i]);
		i++;
	}
}

int	**create_pipes(int num_pipe)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * num_pipe);
	i = 0;
	while (i < num_pipe)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < num_pipe)
	{
		if (pipe(pipes[i]) == -1)
			exit(1);
		i++;
	}
	return (pipes);
}

t_info	*init_info(t_deque *deque)
{
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	info->num_pipe = deque_size(deque) - 1;
	info->pipes = create_pipes(info->num_pipe);
	info->arr_pid = malloc(sizeof(pid_t) * (info->num_pipe + 1));
	return (info);
}

t_deque	*parsing_pipe(char **arg)
{
	int		i;
	t_deque	*deque;
	t_node	*node;

	deque = new_deque();
	node = push_init_new_node(deque);
	i = 0;
	while (arg[i])
	{
		if ((ft_strcmp(arg[i], "<") == 0) || (ft_strcmp(arg[i], ">") == 0) \
		|| (ft_strcmp(arg[i], "<<") == 0) || (ft_strcmp(arg[i], ">>") == 0))
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, arg[i]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], "|") == 0)
		{
			node = push_init_new_node(deque);
			i += 1;
		}
		else
			node->cmd = append_str(node->cmd, arg[i++]);
	}
	return (deque);
}

void	run_cmd(char **arg, char **envp, t_setting **set)
{
	t_deque		*deque;
	t_info		*info;
	t_heredoc	*hdoc;

	deque = parsing_pipe(arg);
	info = init_info(deque);
	hdoc = do_heredoc(arg, deque);
	if (g_exit_status == -5)
	{
		g_exit_status = 0;
		free_run_cmd(deque, info, hdoc);
		return ;
	}
	run_cmd_fork(deque, info, envp, set);
	ft_wait_pids(info, set);
	init_signalaction();
	unlink_temp_file(hdoc);
	free_run_cmd(deque, info, hdoc);
}
