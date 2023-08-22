/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:42:20 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:41:17 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init_map.h"

void	set_camera_part2(t_camera *cam, t_camera2 *s_cam, t_canvas *canvas)
{
	t_vector	w;
	t_vector	u;
	t_vector	v;
	t_vector	vup;

	vup = compute_dynamic_vup(cam->orientation);
	w = vunit(cam->orientation);
	u = vunit(vcross(vup, w));
	v = vcross(w, u);
	cam->fov = s_cam->fov;
	cam->viewport_height = 2.0 * tan((cam->fov * M_PI / 180) / 2);
	cam->viewport_width = cam->viewport_height * canvas->aspect_ratio;
	cam->horizontal = vmult(u, cam->viewport_width);
	cam->vertical = vmult(v, cam->viewport_height);
	cam->left_bottom = vminus(vminus(vminus(cam->origin, \
	vdivide(cam->horizontal, 2)), vdivide(cam->vertical, 2)), w);
}

t_camera	set_camera(t_setting *set, t_canvas canvas)
{
	t_camera	cam;
	t_camera2	*s_cam;

	s_cam = (t_camera2 *)set->object;
	cam.origin = s_cam->origin;
	cam.orientation = s_cam->orientation;
	set_camera_part2(&cam, s_cam, &canvas);
	return (cam);
}

t_vector	set_ambient(t_setting *set)
{
	t_ambient2	*a_info;
	t_vector	normalized_color;
	t_vector	ambient;

	a_info = (t_ambient2 *)set->object;
	normalized_color = vdivide(a_info->color, 255);
	ambient = vmult(normalized_color, a_info->ratio);
	return (ambient);
}

t_object	*set_light(t_setting *set)
{
	t_object	*light;
	t_light2	*l_info;

	l_info = (t_light2 *)set->object;
	light = object(LIGHT_POINT, light_point(l_info->point, \
	vdivide(l_info->color, 255), l_info->brightness), vector(0, 0, 0));
	if (!light)
	{
		printf("Error\nmalloc failed\n");
		exit(1);
	}
	return (light);
}

t_map	*map_init2(t_setting *set)
{
	t_map		*map;
	t_setting	*set_t;

	set_t = set;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->canvas = canvas(WIDTH, HEIGHT);
	while (set_t->next != NULL)
	{
		if (set_t->type[0] == 'C')
			map->camera = set_camera(set_t, map->canvas);
		else if (set_t->type[0] == 'A')
			map->ambient = set_ambient(set_t);
		else if (set_t->type[0] == 'L')
			map->light = set_light(set_t);
		set_t = set_t->next;
	}
	if (size_list(set) != 3)
		map->world = set_world(set);
	return (map);
}
