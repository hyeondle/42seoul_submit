/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:43 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 12:51:56 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	get_heredoc(t_heredoc *hdoc)
{
	int	i;

	hdoc->fd_heredoc = malloc(sizeof(int) * hdoc->size_heredoc);
	i = 0;
	while (i < hdoc->size_heredoc)
	{
		hdoc->fd_heredoc[i] = ft_here_doc(hdoc, i);
		i++;
	}
}

void	parsing_heredoc(char **arg, t_heredoc *hdoc)
{
	int		i;
	char	*new_str;
	char	*new_int;

	i = 0;
	while (arg[i])
	{
		if (ft_strcmp(arg[i], "<<") == 0)
		{
			hdoc->terminators = append_str(hdoc->terminators, arg[i + 1]);
			new_int = ft_itoa(hdoc->size_heredoc);
			new_str = ft_strjoin("./tmp/.here_doc", new_int);
			hdoc->filename_temp = append_str(hdoc->filename_temp, new_str);
			free(new_str);
			free(new_int);
			hdoc->size_heredoc++;
		}
		i++;
	}
}

void	init_t_heredoc(t_heredoc *hdoc)
{
	init_2d_arr(&(hdoc->terminators));
	init_2d_arr(&(hdoc->filename_temp));
	hdoc->size_heredoc = 0;
}

t_heredoc	*do_heredoc(char **arg, t_deque *deque)
{
	t_heredoc	*hdoc;

	hdoc = malloc(sizeof(t_heredoc) * 1);
	init_t_heredoc(hdoc);
	parsing_heredoc(arg, hdoc);
	get_heredoc(hdoc);
	cnt_heredoc_in_node(deque);
	distribute_heredoc(deque, hdoc);
	return (hdoc);
}
