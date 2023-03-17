/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:06:53 by hyeondle          #+#    #+#             */
/*   Updated: 2022/09/24 18:20:37 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_split_all_to_line_one(char *str_all)
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

static char	*get_line(int fd, char *backup, char *buf_temp)
{
	ssize_t	read_size;
	char	*temp;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buf_temp, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		else if (read_size == 0)
			return (backup);
		buf_temp[read_size] = '\0';
		if (!backup)
			backup = ft_strdup2("");
		temp = backup;
		backup = ft_strjoin(temp, buf_temp);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf_temp, '\n'))
			return (backup);
	}
	return (backup);
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
