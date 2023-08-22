/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:42:41 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:45:27 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hit_object.h"
#include <math.h>

t_bool	hit_cylinder_caps(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_bool		bottom_hit;
	t_bool		top_hit;

	cy = obj->element;
	bottom_hit = hit_cylinder_cap_bottom(ray, rec, cy, rec->tmin);
	top_hit = hit_cylinder_cap_top(ray, rec, cy, rec->tmin);
	if (bottom_hit || top_hit)
	{
		rec->albedo = obj->albedo;
		return (TRUE);
	}
	return (FALSE);
}

void	hit_check(t_calcylinder *h, t_cylinder *cy, \
					t_hit_record *rec, t_ray *ray)
{
	double	t1;
	double	t2;
	double	y1;
	double	y2;

	t1 = (-h->b - sqrt(h->discriminant)) / (2 * h->a);
	t2 = (-h->b + sqrt(h->discriminant)) / (2 * h->a);
	y1 = vdot(vminus(ray_at(ray, t1), cy->origin), cy->axis);
	y2 = vdot(vminus(ray_at(ray, t2), cy->origin), cy->axis);
	if (y1 > 0 && y1 < cy->height && t1 > rec->tmin && t1 < rec->tmax)
	{
		h->hit = TRUE;
		h->hit_t = t1;
	}
	if (y2 > 0 && y2 < cy->height && t2 > rec->tmin && t2 < rec->tmax)
	{
		h->hit = TRUE;
		if (t2 < h->hit_t)
			h->hit_t = t2;
	}
}

void	condition_check(t_calcylinder *h, t_cylinder *cy, \
						t_hit_record *rec, t_ray *ray)
{
	h->hit_t = INFINITY;
	h->hit = FALSE;
	h->cap_hit = FALSE;
	if (h->discriminant >= 0)
		hit_check(h, cy, rec, ray);
	if (hit_cylinder_cap_bottom(ray, rec, cy, 0))
	{
		h->cap_hit = TRUE;
		h->cap_normal = rec->normal;
		h->hit_t = rec->t;
	}
	if (hit_cylinder_cap_top(ray, rec, cy, 0) && rec->t < h->hit_t)
	{
		h->cap_hit = TRUE;
		h->cap_normal = rec->normal;
		h->hit_t = rec->t;
	}
}

void	set_rec_cylinder(t_calcylinder h, t_object *obj, \
			t_ray *ray, t_hit_record *rec)
{
	t_vector	op;
	t_cylinder	*cy;

	cy = obj->element;
	rec->t = h.hit_t;
	rec->p = ray_at(ray, h.hit_t);
	if (h.cap_hit)
		rec->normal = h.cap_normal;
	else
	{
		op = vminus(rec->p, cy->origin);
		rec->normal = vunit(vminus(op, vmult(cy->axis, vdot(op, cy->axis))));
	}
	set_face_normal(ray, rec);
	rec->albedo = obj->albedo;
}

t_bool	hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder		*cy;
	t_calcylinder	h;

	cy = obj->element;
	h.oc = vminus(ray->origin, cy->origin);
	h.a = vdot(ray->d_unit, ray->d_unit) - \
			pow(vdot(ray->d_unit, cy->axis), 2);
	h.b = 2 * (vdot(ray->d_unit, h.oc) - \
			vdot(ray->d_unit, cy->axis) * vdot(h.oc, cy->axis));
	h.c = vdot(h.oc, h.oc) - pow(vdot(h.oc, cy->axis), 2) - pow(cy->radius, 2);
	h.discriminant = h.b * h.b - 4 * h.a * h.c;
	h.top_centroid = vplus(cy->origin, vmult(cy->axis, cy->height));
	condition_check(&h, cy, rec, ray);
	if (h.hit || h.cap_hit)
	{
		set_rec_cylinder(h, obj, ray, rec);
		return (TRUE);
	}
	return (FALSE);
}
