/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:50 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:36:12 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	redir_infile(t_node *node, int i)
{
	int	fd_in;

	fd_in = open(node->file_redir[i], O_RDONLY);
	if (fd_in < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
}

void	redir_outfile_ow(t_node *node, int i)
{
	int	fd_out;

	fd_out = open(node->file_redir[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}

void	redir_outfile_apd(t_node *node, int i)
{
	int	fd_out;

	fd_out = open(node->file_redir[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}

void	redir_heredoc(t_node *node, int idx_hd_in_node)
{
	int	fd_in;

	fd_in = open(node->filename_heredoc[idx_hd_in_node], O_RDONLY);
	if (fd_in < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
}
