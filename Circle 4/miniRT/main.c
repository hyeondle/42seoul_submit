/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:55:11 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:56:57 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/mylibft.h"
#include "./minilibx/mlx.h"
#include <math.h>
#include "./includes/object.h"
#include "./includes/trace.h"
#include "./includes/vector.h"
#include "./includes/map.h"
#include "./includes/sets.h"
#include "./includes/draw.h"
#include "./includes/hit_object.h"
#include "./includes/ft_atof.h"
#include "./includes/set_object.h"
#include "./includes/parser.h"
#include "./includes/init_map.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	esc_game(t_base *base)
{
	mlx_destroy_window(base->mlx, base->win);
	exit(1);
}

int	hook_key_press(int key_code, t_base *base)
{
	if (key_code == KEY_ESC)
		esc_game(base);
	return (0);
}

t_base	*base_init(t_canvas canvas)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
	{
		printf("Error\nmalloc error\n");
		exit(1);
	}
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, canvas.width, \
	canvas.height, "miniRT");
	base->img = mlx_new_image(base->mlx, canvas.width, canvas.height);
	base->addr = mlx_get_data_addr(base->img, &(base->bpp), \
								&(base->size_line), &(base->endian));
	if (!base->mlx || !base->win || !base->img || !base->addr)
	{
		printf("Error\nmlx init error\n");
		exit(1);
	}
	return (base);
}

int	main(int argc, char **argv)
{
	t_setting	*set;
	t_map		*map;
	t_base		*base;

	check_extension(argc, argv);
	set = parser(argc, argv);
	map = map_init2(set);
	base = base_init(map->canvas);
	draw(map, base);
	mlx_hook(base->win, DESTROY_NOTIFY, 0, &esc_game, base);
	mlx_hook(base->win, KEY_PRESS, 0, &hook_key_press, base);
	mlx_loop(base->mlx);
	free_set(set);
	free_obj(map->light);
	free_obj(map->world);
	free(map);
	return (0);
}
