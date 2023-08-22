/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:15:02 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:28:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"
#include <math.h>
#include "../includes/hit_object.h"

t_vector	phong_lighting(t_map *map)
{
	t_vector	light_color;
	t_object	*light;

	light_color = vector(0, 0, 0);
	light = map->light;
	while (light)
	{
		if (light->type == LIGHT_POINT)
			light_color = vplus(light_color, \
								point_light_get(map, light->element));
		light = light->next;
	}
	light_color = vplus(light_color, map->ambient);
	return (vmin(vmult_2(light_color, vdivide(map->rec.albedo, 255)), \
			vector(1, 1, 1)));
}

t_vector	point_light_get(t_map *map, t_light *light)
{
	t_phong_light	ls;

	ls.light_direction = vminus(light->origin, map->rec.p);
	ls.light_length = vlength(ls.light_direction);
	ls.light_ray = ray(vplus(map->rec.p, vmult(map->rec.normal, EPSILON)), \
					ls.light_direction);
	if (in_shadow(map->world, ls.light_ray, ls.light_length))
		return (vector(0, 0, 0));
	ls.light_direction = vunit(ls.light_direction);
	ls.kd = fmax(vdot(map->rec.normal, ls.light_direction), 0.0);
	ls.diffuse = vmult(light->color, ls.kd);
	ls.view_direction = vunit(vmult(map->ray.d_unit, -1));
	ls.reflect_direction = reflect(vmult(ls.light_direction, -1), \
									map->rec.normal);
	ls.ksn = 64;
	ls.ks = 0.5;
	ls.spec = pow(fmax(vdot(ls.view_direction, ls.reflect_direction), 0.0), \
					ls.ksn);
	ls.specular = vmult(vmult(light->color, ls.ks), ls.spec);
	ls.brightness = light->brightness * LUMEN;
	return (vmult(vplus(ls.diffuse, ls.specular), ls.brightness));
}

t_vector	reflect(t_vector v, t_vector n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_bool	in_shadow(t_object *objects, t_ray light_ray, double light_length)
{
	t_hit_record	record;

	record.tmin = 0;
	record.tmax = light_length;
	if (hit(objects, &light_ray, &record))
		return (TRUE);
	return (FALSE);
}
