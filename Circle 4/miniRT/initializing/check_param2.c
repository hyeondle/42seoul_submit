/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:26:44 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/13 16:45:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_bool	check_param_rgb(char *str)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (size_2arr(rgb) != 3)
		return (free_false(rgb));
	i = 0;
	while (rgb[i] != NULL)
	{
		if (check_param_int(rgb[i], 0, 255) == FALSE)
			return (free_false(rgb));
		i++;
	}
	free_info(rgb);
	return (TRUE);
}

t_bool	check_param_double(char *str, double min, double max)
{
	double	num;

	num = ft_atof(str);
	if (!(min <= num && num <= max))
		return (FALSE);
	else
		return (TRUE);
}

t_bool	check_param_a(char **info)
{
	if (size_2arr(info) != 3)
		return (FALSE);
	if (check_param_double(info[1], 0.0, 1.0) == FALSE)
		return (FALSE);
	if (check_param_rgb(info[2]) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_param_c(char **info)
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
	if (check_param_int(info[3], 0, 180) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_param_l(char **info)
{
	char	**xyz;

	if (!(size_2arr(info) == 4 || size_2arr(info) == 3))
		return (FALSE);
	xyz = ft_split(info[1], ',');
	if (size_2arr(xyz) != 3)
	{
		free_info(xyz);
		return (FALSE);
	}
	free_info(xyz);
	if (check_param_double(info[2], 0.0, 1.0) == FALSE)
		return (FALSE);
	return (TRUE);
}
