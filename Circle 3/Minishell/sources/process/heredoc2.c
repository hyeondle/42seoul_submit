/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:44 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:35:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/minishell.h"

void	cnt_heredoc_in_node(t_deque *deque)
{
	t_node	*node;
	int		i;

	node = deque->front;
	while (node)
	{
		i = 0;
		while (node->order_redir[i])
		{
			if (ft_strcmp(node->order_redir[i], "<<") == 0)
				node->num_heredoc++;
			i++;
		}
		node = node->next;
	}
}

void	distribute_heredoc(t_deque *deque, t_heredoc *hdoc)
{
	t_node	*node;
	int		idx_hd;
	int		i;

	idx_hd = 0;
	node = deque->front;
	while (node)
	{
		i = 0;
		while (i < node->num_heredoc)
		{
			node->filename_heredoc = append_str(node->filename_heredoc, \
			hdoc->filename_temp[idx_hd]);
			idx_hd++;
			i++;
		}
		node = node->next;
	}
}

void	ft_here_doc_child(int idx, int *here_fd, t_heredoc *hdoc)
{
	char	*str;

	ft_signal_child_hd();
	while (1)
	{
		str = readline("> ");
		if (!str || ft_strcmp(hdoc->terminators[idx], str) == 0)
		{
			if (str)
				free(str);
			exit(0);
		}
		write(*here_fd, str, ft_strlen(str));
		write(*here_fd, "\n", 1);
		free(str);
	}
}

int	ft_here_doc(t_heredoc *hdoc, int idx)
{
	pid_t	pid;
	int		here_fd;
	int		status;

	here_fd = open(hdoc->filename_temp[idx], O_RDWR | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		ft_here_doc_child(idx, &here_fd, hdoc);
	ignores();
	wait(&status);
	if (WIFSIGNALED(status))
		g_exit_status = -5;
	init_signalaction();
	return (here_fd);
}
