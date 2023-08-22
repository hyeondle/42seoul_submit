/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:07:41 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:06:27 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "./vector.h"

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}			t_canvas;

typedef struct s_camera
{
	t_vector	origin;
	double		viewport_height;
	double		viewport_width;
	t_vector	horizontal;
	t_vector	vertical;
	double		focal_length;
	t_vector	left_bottom;
	t_vector	lookfrom;
	t_vector	lookat;
	t_vector	upvector;
	t_vector	orientation;
	double		fov;
	t_vector	w;
	t_vector	u;
	t_vector	v;
}				t_camera;

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_vector origin, double fov);

#endif