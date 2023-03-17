/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:21:26 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:22:48 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_view	*view_init(t_base *base)
{
	t_view	*view;
	int		scale_w;
	int		scale_h;

	view = (t_view *)ft_calloc(sizeof(t_view));
	if (!view)
		goterror(ERR_MALLOC);
	scale_w = WIDTH / base->map->map_width / 2;
	scale_h = HEIGHT / base->map->map_height / 2;
	if (scale_w < scale_h)
		view->scale = scale_w;
	else
		view->scale = scale_h;
	view->theta_x = 0;
	view->theta_y = 0;
	view->theta_z = 0;
	view->offset_x = 0;
	view->offset_y = 0;
	view->z_div_num = 0;
	view->projection = 1;
	return (view);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(t_map));
	if (!map)
		goterror(ERR_MAP_INIT);
	map->map_width = 0;
	map->map_height = 0;
	map->z_range = 0;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	map->z_point_array = NULL;
	map->z_color_array = NULL;
	return (map);
}

t_base	*base_init(t_map *map)
{
	t_base	*base;

	base = (t_base *)ft_calloc(sizeof(t_base));
	if (!base)
		goterror(ERR_MLX_INIT);
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "FdF");
	base->img = mlx_new_image(base->mlx, WIDTH, HEIGHT);
	base->addr = mlx_get_data_addr(base->img, &(base->bpp), \
								&(base->size_line), &(base->endian));
	base->map = map;
	if (!base->mlx || !base->win || !base->img || !base->addr || !base->map)
		goterror(ERR_MLX_INIT);
	return (base);
}
