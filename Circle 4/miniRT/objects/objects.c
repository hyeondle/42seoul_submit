/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:18:55 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:29:03 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/object.h"
#include <stdlib.h>

t_light	*light_point(t_vector origin, t_vector color, double brightness)
{
	t_light	*light;

	(light = (t_light *)malloc(sizeof(t_light)));
	if (!light)
		return (NULL);
	light->origin = origin;
	light->color = color;
	light->brightness = brightness;
	return (light);
}

t_sphere	*sphere(t_vector center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plane	*plane(t_vector origin, t_vector normal)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->origin = origin;
	pl->normal = normal;
	return (pl);
}

t_cylinder	*cylinder(t_vector origin, t_vector axis, \
						double radius, double height)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->origin = origin;
	cy->axis = axis;
	cy->radius = radius;
	cy->height = height;
	return (cy);
}
