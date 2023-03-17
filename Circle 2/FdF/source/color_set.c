/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:07:51 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:09:10 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ratio(double per, int color_start, int color_end)
{
	return ((int)((1 - per) * color_start + per * color_end));
}

int	get_color(t_point p, t_point n, int x)
{
	t_color	*set;
	int		color;

	set = (t_color *)malloc(sizeof(t_color));
	if (!set)
	{
		goterror(ERR_MALLOC);
		return (0);
	}
	if (n.x - p.x == 0)
		set->per = 0.5;
	else
		set->per = (double)(x - p.x) / (double)(n.x - p.x);
	set->r = ratio(set->per, (p.color >> 16) & 0xFF, (n.color >> 16) & 0xFF);
	set->g = ratio(set->per, (p.color >> 8) & 0xFF, (n.color >> 8) & 0xFF);
	set->b = ratio(set->per, p.color, n.color);
	color = (set->r << 16) + (set->g << 8) + set->b;
	free(set);
	return (color);
}

int	color_set(int x, t_point p, t_point n)
{
	int	color;

	if (p.color == n.color)
		return (p.color);
	color = get_color(p, n, x);
	return (color);
}
