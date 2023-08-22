/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:43:04 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:41:34 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MAP_H
# define INIT_MAP_H

# include "./sets.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

void		set_camera_part2(t_camera *cam, t_camera2 *s_cam, t_canvas *canvas);
t_camera	set_camera(t_setting *set, t_canvas canvas);
t_vector	set_ambient(t_setting *set);
t_object	*set_light(t_setting *set);
t_map		*map_init2(t_setting *set);
int			get_type(t_setting *set);
t_object	*primary_object(t_setting *set, int type);
void		object_add(t_setting *set, int type, t_object *world);
void		set_world_part2(int *object_type, t_setting **set_t, \
t_object **world);
t_object	*set_world(t_setting *set);
int			size_list(t_setting *set);
t_vector	compute_dynamic_vup(t_vector orientation);

#endif