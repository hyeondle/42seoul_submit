/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:33:03 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/21 11:43:22 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hit_object.h"
#include <math.h>

void	hit_cylinder_set_info(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double t)
{
	rec->t = t;
	rec->p = ray_at(ray, t);
	if (vdot(cy->axis, ray->d_unit) < 0)
		rec->normal = cy->axis;
	else
		rec->normal = vmult(cy->axis, -1);
	set_face_normal(ray, rec);
}

t_bool	hit_cylinder_cap_hit_bottom(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t)
{
	t_vector	oc;
	t_vector	cap_center;
	t_vector	dfc;
	double		t;

	cap_center = cy->origin;
	oc = vminus(cap_center, ray->origin);
	t = vdot(oc, cy->axis) / vdot(cy->axis, ray->d_unit);
	if (t > min_t + EPSILON && t < rec->tmax - EPSILON)
	{
		dfc = vminus(ray_at(ray, t), cap_center);
		dfc = vminus(dfc, vmult(cy->axis, vdot(dfc, cy->axis)));
		if (vdot(dfc, dfc) <= cy->radius * cy->radius)
		{
			hit_cylinder_set_info(ray, rec, cy, t);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	hit_cylinder_cap_hit_top(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t)
{
	t_vector	oc;
	t_vector	cap_center;
	t_vector	dfc;
	double		t;

	cap_center = vplus(cy->origin, vmult(cy->axis, cy->height));
	oc = vminus(cap_center, ray->origin);
	t = vdot(oc, cy->axis) / vdot(cy->axis, ray->d_unit);
	if (t > min_t + EPSILON && t < rec->tmax - EPSILON)
	{
		dfc = vminus(ray_at(ray, t), cap_center);
		dfc = vminus(dfc, vmult(cy->axis, vdot(dfc, cy->axis)));
		if (vdot(dfc, dfc) <= cy->radius * cy->radius)
		{
			hit_cylinder_set_info(ray, rec, cy, t);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	hit_cylinder_cap_bottom(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t)
{
	double		denominator;

	denominator = vdot(cy->axis, ray->d_unit);
	if (denominator < 0)
		return (FALSE);
	if (fabs(denominator) > EPSILON)
	{
		if (hit_cylinder_cap_hit_bottom(ray, rec, cy, min_t))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	hit_cylinder_cap_top(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t)
{
	double		denominator;

	denominator = vdot(cy->axis, ray->d_unit);
	if (denominator > 0)
		return (FALSE);
	if (fabs(denominator) > EPSILON)
	{
		if (hit_cylinder_cap_hit_top(ray, rec, cy, min_t))
			return (TRUE);
	}
	return (FALSE);
}
