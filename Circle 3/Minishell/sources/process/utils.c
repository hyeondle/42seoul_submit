/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:54 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 10:44:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_p_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	putstr_exit(char *str, int fd, int exit_code)
{
	ft_putstr_fd(str, fd);
	exit(exit_code);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	init_2d_arr(char ***arr)
{
	*arr = malloc(sizeof(char *));
	(*arr)[0] = NULL;
}

char	**append_str(char **arg, char *str)
{
	int		i;
	int		size;
	char	**new_arr;

	size = 0;
	if (!arg)
		size = 0;
	else
		while (arg[size])
			size++;
	new_arr = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (i < size)
	{
		new_arr[i] = (char *)malloc(ft_strlen(arg[i]) + 1);
		ft_strlcpy(new_arr[i], arg[i], ft_strlen(arg[i]) + 1);
		i++;
	}
	new_arr[i] = malloc(ft_strlen(str) + 1);
	ft_strlcpy(new_arr[i], str, ft_strlen(str) + 1);
	i++;
	new_arr[i] = NULL;
	if (arg)
		free_2d_array(arg);
	return (new_arr);
}
