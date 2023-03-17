/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:06:15 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:07:07 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(M_PI / 6);
	*y = -z + (previous_x + previous_y) * sin(M_PI / 6);
}

t_point	project(t_point p, t_base *base)
{
	p.x *= base->view->scale / 2;
	p.y *= base->view->scale / 2;
	p.z *= base->view->scale / 2 + base->view->z_div_num;
	p.x -= (base->map->map_width * base->view->scale) / 2;
	p.y -= (base->map->map_height * base->view->scale) / 2;
	rotate_x(&p.y, &p.z, base->view->theta_x);
	rotate_y(&p.x, &p.z, base->view->theta_y);
	rotate_z(&p.x, &p.y, base->view->theta_z);
	if (base->view->projection == 1)
		isometric(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + base->view->offset_x;
	p.y += (HEIGHT + base->map->map_height * base->view->scale) / 2 \
											+ base->view->offset_y;
	return (p);
}
