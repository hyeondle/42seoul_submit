/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:06:53 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/18 16:46:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*do_split_all_to_line_one(char *str_all)
{
	char	*str_after;
	int		i;

	i = 0;
	while (str_all[i] != '\n' && str_all[i] != '\0')
		i++;
	if (str_all[i] == '\0')
		return (NULL);
	str_after = ft_substr_gnl(str_all, i + 1, ft_strlen_gnl(str_all) - i);
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
			backup = ft_strdup_gnl("");
		temp = backup;
		backup = ft_strjoin_gnl(temp, buf_temp);
		free(temp);
		temp = NULL;
		if (ft_strchr_gnl(buf_temp, '\n'))
			return (backup);
	}
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf_temp;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf_temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_temp)
		return (NULL);
	return_str = get_line(fd, backup, buf_temp);
	free(buf_temp);
	buf_temp = NULL;
	if (!return_str)
		return (NULL);
	backup = do_split_all_to_line_one(return_str);
	return (return_str);
}
