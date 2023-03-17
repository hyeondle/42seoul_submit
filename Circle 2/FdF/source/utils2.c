/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:04:04 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:20:46 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	init_delta(t_point p, t_point n)
{
	t_point	delta;

	delta.x = abs(n.x - p.x);
	delta.y = abs(n.y - p.y);
	return (delta);
}

t_point	init_flag(t_point p, t_point n)
{
	t_point	flag;

	flag.x = 1;
	flag.y = 1;
	if (n.x < p.x)
		flag.x = -1;
	if (n.y < p. y)
		flag.y = -1;
	return (flag);
}
