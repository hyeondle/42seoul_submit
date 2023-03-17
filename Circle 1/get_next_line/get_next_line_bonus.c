/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:32:03 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/26 14:22:37 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*fd_check(t_list *box, int fd);
t_list	*get_box(t_list *box, t_list *temp_box, int b_case, int fd);

char	*do_split_all_to_line_one(char *str_all)
{
	char	*str_after;
	int		i;

	i = 0;
	while (str_all[i] != '\n' && str_all[i] != '\0')
		i++;
	if (str_all[i] == '\0')
		return (NULL);
	str_after = ft_substr(str_all, i + 1, ft_strlen(str_all) - i);
	if (!str_after)
		return (NULL);
	if (str_after[0] == '\0')
	{
		free(str_after);
		str_after = NULL;
		return (NULL);
	}
	str_all[i + 1] = '\0';
	return (str_after);
}

char	*get_line(int fd, char *backup, char *buf_temp)
{
	ssize_t	read_size;
	char	*temp;

	while (1)
	{
		read_size = read(fd, buf_temp, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		else if (read_size == 0)
			return (backup);
		buf_temp[read_size] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf_temp);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf_temp, '\n'))
			return (backup);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*box;
	char			*buf_temp;
	char			*return_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf_temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_temp)
		return (NULL);
	box = fd_check(box, fd);
	return_str = get_line(fd, box->backup, buf_temp);
	free(buf_temp);
	buf_temp = NULL;
	if (!return_str)
		return (NULL);
	box->backup = do_split_all_to_line_one(return_str);
	return (return_str);
}

t_list	*fd_check(t_list *box, int fd)
{
	t_list	*temp_box;

	temp_box = (t_list *)malloc(sizeof(t_list));
	if (!box)
		box = get_box(box, temp_box, 0, fd);
	if (box->fd > 2 && box->fd != fd)
	{
		while (box->fd < fd && box->next != NULL)
		{
			box = box->next;
			if (box->next == NULL)
				box = get_box(box, temp_box, 1, fd);
		}
		while (box->fd > fd && box->prev != NULL)
		{
			box = box->prev;
			if (box->prev == NULL)
				box = get_box(box, temp_box, 2, fd);
		}
	}
	return (box);
}

t_list	*get_box(t_list *box, t_list *temp_box, int b_case, int fd)
{
	if (temp_box)
	{
		temp_box->fd = fd;
		temp_box->prev = NULL;
		temp_box->next = NULL;
		temp_box->backup = NULL;
	}
	if (b_case == 1)
	{
		box->next = temp_box;
		box = temp_box;
	}
	else if (b_case == 2)
	{
		box->prev = temp_box;
		box = temp_box;
	}
	else
		box = temp_box;
	return (box);
}
