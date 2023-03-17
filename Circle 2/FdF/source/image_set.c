/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:51:16 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 14:10:10 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//get x, y, z, color and init t_point for check the pixel's locate
t_point	new_dot(int x, int y, t_map *map)
{
	t_point	dot;
	int		i;

	i = x + y * map->map_width;
	dot.x = x;
	dot.y = y;
	dot.z = map->z_point_array[i];
	dot.color = map->z_color_array[i];
	return (dot);
}

void	locate_pixel(t_base *base, int x, int y, int color)
{
	char	*pixel_address;

	pixel_address = base->addr + (x * (base->bpp / 8) + y * base->size_line);
	*(unsigned int *)pixel_address = color;
}

void	draw_line(t_point dot_prev, t_point dot_next, t_base *base)
{
	t_point	dot;
	t_point	delta;
	t_point	flag;
	int		line[2];

	delta = init_delta(dot_prev, dot_next);
	flag = init_flag(dot_prev, dot_next);
	line[0] = delta.x - delta.y;
	dot.x = dot_prev.x;
	dot.y = dot_prev.y;
	while (dot.x != dot_next.x || dot.y != dot_next.y)
	{
		locate_pixel(base, dot.x, dot.y, color_set(dot.x, dot_prev, dot_next));
		line[1] = line[0] * 2;
		if (line[1] > -delta.y)
		{
			line[0] -= delta.y;
			dot.x += flag.x;
		}
		if (line[1] < delta.x)
		{
			line[0] += delta.x;
			dot.y += flag.y;
		}
	}
}

void	draw_background(t_base *base)
{
	int	height;
	int	width;

	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			locate_pixel(base, width, height, BLACK);
			width++;
		}
		height++;
	}
}

void	draw_image(t_map *map, t_base *base)
{
	int	x;
	int	y;

	y = 0;
	draw_background(base);
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (x != base->map->map_width - 1)
				draw_line(project(new_dot(x, y, map), base), \
						project(new_dot(x + 1, y, map), base), base);
			if (y != base->map->map_height - 1)
				draw_line(project(new_dot(x, y, map), base), \
						project(new_dot(x, y + 1, map), base), base);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
}
