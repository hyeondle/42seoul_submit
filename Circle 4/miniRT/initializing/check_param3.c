/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:27:40 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:38:29 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	size_2arr(char **arr)
{
	int	size;

	size = 0;
	while (arr[size] != NULL)
	{
		size++;
	}
	return (size);
}

t_bool	check_param_int(char *str, int min, int max)
{
	int	num;

	num = ft_atoi(str);
	if (!(min <= num && num <= max))
		return (FALSE);
	else
		return (TRUE);
}

t_bool	free_false(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (FALSE);
}

void	free_p_exit(char **arr)
{
	free_info(arr);
	p_exit("wrong arguments.", 1);
}

void	check_extension(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		p_exit("Input arguments", 1);
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 1] == 't' && argv[1][len - 2] == 'r' \
	&& argv[1][len - 3] == '.'))
		p_exit("Input arguments", 1);
}
