/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:44:36 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 11:50:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//control stacks
#include "fdf.h"

// return each stack's value addr and make stack next
t_dotz	*get_stack_addr(t_dotz **dotz_stack)
{
	t_dotz	*first;

	first = NULL;
	if (dotz_stack && *dotz_stack)
	{
		first = *dotz_stack;
		*dotz_stack = (*dotz_stack)->next;
	}
	return (first);
}

// init struct of t_dotz
void	set_map(t_dotz **dotz_stack, t_map *map)
{
	t_dotz	*stack;
	int		i;
	int		array_size;

	array_size = sizeof(int) * map->map_width * map->map_height;
	map->z_point_array = (int *)malloc(array_size);
	if (!map->z_point_array)
		goterror(ERR_MALLOC);
	map->z_color_array = (int *)malloc(array_size);
	if (!map->z_color_array)
		goterror(ERR_MALLOC);
	i = map->map_width * map->map_height - 1;
	while (i >= 0)
	{
		stack = get_stack_addr(dotz_stack);
		map->z_point_array[i] = stack->z;
		map->z_color_array[i] = stack->color;
		if (stack->z > map->z_max)
			map->z_max = stack->z;
		if (stack->z < map->z_min)
			map->z_min = stack->z;
		i--;
		free(stack);
	}
	map->z_range = map->z_max - map->z_min;
}
