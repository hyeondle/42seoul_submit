/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:10:29 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/13 16:02:02 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/set_object.h"

t_light2	*i_light(char **info)
{
	t_light2	*light;

	light = (t_light2 *)malloc(sizeof(t_light2));
	light->point = mv(info[1]);
	light->brightness = ft_atof(info[2]);
	if (info[3])
		light->color = mv(info[3]);
	else
		light->color = vector(255, 255, 255);
	return (light);
}

t_sphere2	*i_sphere(char **info)
{
	t_sphere2	*sphere;

	sphere = (t_sphere2 *)malloc(sizeof(t_sphere2));
	sphere->origin = mv(info[1]);
	sphere->diameter = ft_atof(info[2]);
	sphere->color = mv(info[3]);
	return (sphere);
}

t_plane2	*i_plane(char **info)
{
	t_plane2	*plane;

	plane = (t_plane2 *)malloc(sizeof(t_plane2));
	plane->point = mv(info[1]);
	plane->normal = vunit(mv(info[2]));
	plane->color = mv(info[3]);
	return (plane);
}

t_cylinder2	*i_cylinder(char **info)
{
	t_cylinder2	*cylinder;

	cylinder = (t_cylinder2 *)malloc(sizeof(t_cylinder2));
	cylinder->origin = mv(info[1]);
	cylinder->axis = vunit(mv(info[2]));
	cylinder->diameter = ft_atof(info[3]);
	cylinder->height = ft_atof(info[4]);
	cylinder->color = mv(info[5]);
	return (cylinder);
}

void	*object_set(char **info)
{
	char	*type;

	type = info[0];
	if (type[0] == 'A' && type[1] == '\0')
		return ((void *)i_ambient(info));
	else if (type[0] == 'C' && type[1] == '\0')
		return ((void *)i_camera(info));
	else if (type[0] == 'L' && type[1] == '\0')
		return ((void *)i_light(info));
	else if (type[0] == 's' && type[1] == 'p' && type[2] == '\0')
		return ((void *)i_sphere(info));
	else if (type[0] == 'p' && type[1] == 'l' && type[2] == '\0')
		return ((void *)i_plane(info));
	else if (type[0] == 'c' && type[1] == 'y' && type[2] == '\0')
		return ((void *)i_cylinder(info));
	else
		return (NULL);
}
