/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:46:58 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/19 21:38:45 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init_map.h"

int	get_type(t_setting *set)
{
	char	f;
	char	s;
	char	t;

	f = set->type[0];
	s = set->type[1];
	t = set->type[2];
	if (f == 's' && s == 'p' && t == '\0')
		return (SP);
	if (f == 'p' && s == 'l' && t == '\0')
		return (PL);
	if (f == 'c' && s == 'y' && t == '\0')
		return (CY);
	return (0);
}

t_object	*primary_object(t_setting *set, int type)
{
	t_sphere2	*sp;
	t_plane2	*pl;
	t_cylinder2	*cy;

	if (type == SP)
	{
		sp = (t_sphere2 *)set->object;
		return (object(SP, sphere(sp->origin, sp->diameter), sp->color));
	}
	if (type == PL)
	{
		pl = (t_plane2 *)set->object;
		return (object(PL, plane(pl->point, pl->normal), pl->color));
	}
	if (type == CY)
	{
		cy = (t_cylinder2 *)set->object;
		return (object(CY, cylinder(cy->origin, cy->axis, \
		cy->diameter, cy->height), cy->color));
	}
	return (NULL);
}

void	object_add(t_setting *set, int type, t_object *world)
{
	t_sphere2	*sp;
	t_plane2	*pl;
	t_cylinder2	*cy;

	if (type == SP)
	{
		sp = (t_sphere2 *)set->object;
		oadd(&world, (object(SP, sphere(sp->origin, sp->diameter), sp->color)));
	}
	if (type == PL)
	{
		pl = (t_plane2 *)set->object;
		oadd(&world, (object(PL, plane(pl->point, pl->normal), pl->color)));
	}
	if (type == CY)
	{
		cy = (t_cylinder2 *)set->object;
		oadd(&world, (object(CY, cylinder(cy->origin, cy->axis, \
		cy->diameter, cy->height), cy->color)));
	}
}

void	set_world_part2(int *object_type, t_setting **set_t, t_object **world)
{
	*object_type = get_type(*set_t);
	if (*world == NULL && *object_type != 0)
		*world = primary_object(*set_t, *object_type);
	else if (*object_type != 0)
		object_add(*set_t, *object_type, *world);
	else
	{
		printf("Error\nwrong map file\n");
		exit(1);
	}
}

t_object	*set_world(t_setting *set)
{
	t_setting	*set_t;
	t_object	*world;
	int			object_type;

	object_type = 0;
	world = NULL;
	set_t = set;
	while (set_t->type != NULL)
	{
		if (set_t->type[0] == 'C' || set_t->type[0] == 'A' \
		|| set_t->type[0] == 'L')
		{
			set_t = set_t->next;
			continue ;
		}
		set_world_part2(&object_type, &set_t, &world);
		if (set_t->next == NULL)
			break ;
		set_t = set_t->next;
	}
	return (world);
}
