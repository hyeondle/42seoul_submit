/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:25:51 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/13 16:45:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_bool	check_param_sp(char **info)
{
	char	**xyz;

	if (size_2arr(info) != 4)
		return (FALSE);
	xyz = ft_split(info[1], ',');
	if (size_2arr(xyz) != 3)
		return (free_false(xyz));
	free_info(xyz);
	if (check_param_rgb(info[3]) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_param_pl(char **info)
{
	char	**xyz;
	char	**vect;
	int		i;

	if (size_2arr(info) != 4)
		return (FALSE);
	xyz = ft_split(info[1], ',');
	if (size_2arr(xyz) != 3)
		return (free_false(xyz));
	free_info(xyz);
	vect = ft_split(info[2], ',');
	if (size_2arr(vect) != 3)
		return (free_false(vect));
	i = 0;
	while (vect[i] != NULL)
	{
		if (check_param_double(vect[i], -1.0, 1.0) == FALSE)
			return (free_false(vect));
		i++;
	}
	free_info(vect);
	if (check_param_rgb(info[3]) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_param_cy(char **info)
{
	char	**xyz;
	char	**vect;
	int		i;

	if (size_2arr(info) != 6)
		return (FALSE);
	xyz = ft_split(info[1], ',');
	if (size_2arr(xyz) != 3)
		return (free_false(xyz));
	free_info(xyz);
	vect = ft_split(info[2], ',');
	if (size_2arr(vect) != 3)
		return (free_false(vect));
	i = 0;
	while (vect[i] != NULL)
	{
		if (check_param_double(vect[i], -1.0, 1.0) == FALSE)
			return (free_false(vect));
		i++;
	}
	free_info(vect);
	if (check_param_rgb(info[5]) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_param2(char **info)
{
	char	*type;

	type = info[0];
	if (type[0] == 's' && type[1] == 'p' && type[2] == '\0')
	{
		if (check_param_sp(info) == FALSE)
			return (FALSE);
	}
	else if (type[0] == 'p' && type[1] == 'l' && type[2] == '\0')
	{
		if (check_param_pl(info) == FALSE)
			return (FALSE);
	}
	else if (type[0] == 'c' && type[1] == 'y' && type[2] == '\0')
	{
		if (check_param_cy(info) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

t_bool	check_param(char **info)
{
	char	*type;

	type = info[0];
	if (type[0] == 'A' && type[1] == '\0')
	{
		if (check_param_a(info) == FALSE)
			return (FALSE);
	}
	else if (type[0] == 'C' && type[1] == '\0')
	{
		if (check_param_c(info) == FALSE)
			return (FALSE);
	}
	else if (type[0] == 'L' && type[1] == '\0')
	{
		if (check_param_l(info) == FALSE)
			return (FALSE);
	}
	else
	{
		if (check_param2(info) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
