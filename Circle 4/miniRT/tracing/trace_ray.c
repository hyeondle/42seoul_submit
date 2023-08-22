/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:21:48 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 19:11:41 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"
#include "../includes/hit_object.h"

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.d_unit = vminus(vplus(cam->left_bottom, \
	(vplus(vmult(cam->horizontal, u), vmult(cam->vertical, v)))), cam->origin);
	return (ray);
}

t_vector	ray_color(t_map	*map)
{
	double		t;

	map->rec = record_init();
	if (hit(map->world, &map->ray, &map->rec))
		return (phong_lighting(map));
	else
	{
		t = 0.5 * (map->ray.d_unit.y + 1.0);
		return (vplus(vmult(vector(1, 1, 1), 1.0 - t), \
		vmult(vector(0.0, 0.0, 0.0), t)));
	}
}
