/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:20:41 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 19:11:28 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hit_object.h"
#include <math.h>

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_bool	hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_calsphere	cal;

	sp = obj->element;
	cal.oc = vminus(ray->origin, sp->center);
	cal.a = vlength_pow2(ray->d_unit);
	cal.b = vdot(cal.oc, ray->d_unit) * 2;
	cal.c = vlength_pow2(cal.oc) - sp->radius2;
	cal.discriminant = pow((cal.b / 2), 2) - cal.a * cal.c;
	if (cal.discriminant < 0)
		return (FALSE);
	cal.sqrtd = sqrt(cal.discriminant);
	cal.root = (-(cal.b / 2) - cal.sqrtd) / cal.a;
	if (cal.root < rec->tmin || rec->tmax < cal.root)
	{
		cal.root = (-(cal.b / 2) + cal.sqrtd) / cal.a;
		if (cal.root < rec->tmin || rec->tmax < cal.root)
			return (FALSE);
	}
	rec->t = cal.root;
	rec->p = ray_at(ray, cal.root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
	return (TRUE);
}

t_bool	hit_plane(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane		*pl;
	double		t;
	double		denominator;
	t_vector	oc;

	pl = obj->element;
	denominator = vdot(pl->normal, ray->d_unit);
	if (denominator > EPSILON || denominator < -EPSILON)
	{
		oc = vminus(pl->origin, ray->origin);
		t = vdot(oc, pl->normal) / denominator;
		if (t > rec->tmin && t < rec->tmax)
		{
			rec->t = t;
			rec->p = ray_at(ray, t);
			rec->normal = vunit(pl->normal);
			set_face_normal(ray, rec);
			rec->albedo = obj->albedo;
			return (TRUE);
		}
	}
	return (FALSE);
}
