/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:53:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:28:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_history	*empty_history(void)
{
	t_history	*hist;

	hist = (t_history *)malloc(sizeof(t_history));
	if (!hist)
		return (NULL);
	hist->history = NULL;
	hist->next = NULL;
	return (hist);
}

static t_history	*ft_add_l_history(t_history *temp, char	*str)
{
	t_history	*new_hist;
	t_history	*previous_history;

	previous_history = temp;
	previous_history->history = ft_strdup(str);
	new_hist = (t_history *)malloc(sizeof(t_history));
	if (!new_hist)
		return (NULL);
	new_hist->history = NULL;
	new_hist->next = NULL;
	previous_history->next = new_hist;
	return (new_hist);
}

void	init_history(t_setting **setting)
{
	t_history	*temp;
	char		*str;
	int			fd;
	int			i;

	i = 0;
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd == -1)
		return ;
	str = get_next_line(fd);
	(*setting)->l_history = empty_history();
	if (!(*setting)->l_history)
		return ;
	temp = (*setting)->l_history;
	while (str)
	{
		temp = ft_add_l_history(temp, str);
		add_history(str);
		i++;
		str = get_next_line(fd);
	}
	temp->history = ft_strdup("");
	temp->next = NULL;
	close(fd);
}
