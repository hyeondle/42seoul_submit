/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:59:49 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/08 14:53:33 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vector.h"
#include "./minilibx/mlx.h"
#include "./includes/sets.h"
#include "stdlib.h"

void	locate_pixel(t_base *base, int x, int y, int color)
{
	char	*pixel_address;

	pixel_address = base->addr + (x * (base->bpp / 8) + y * base->size_line);
	*(unsigned int *)pixel_address = color;
}

void	write_color(t_vector pixel_color, t_base *base, int x, int y)
{
	int	color;

	color = ((int)(255.999 * pixel_color.x) << 16) + \
	((int)(255.999 * pixel_color.y) << 8) + (int)(255.999 * pixel_color.z);
	locate_pixel(base, x, y, color);
}

void	draw(t_map *map, t_base *base)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_vector	pixel_color;

	j = map->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < map->canvas.width)
		{
			u = (double)i / (map->canvas.width - 1);
			v = (double)j / (map->canvas.height - 1);
			map->ray = ray_primary(&map->camera, u, v);
			pixel_color = ray_color(map);
			write_color(pixel_color, base, i, ft_abs(j - map->canvas.height));
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(base->mlx, base->win, base->img, 0, 0);
}
