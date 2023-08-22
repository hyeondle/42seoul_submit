/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:56:40 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:26:58 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_ray	ray(t_vector o, t_vector d)
{
	t_ray	ray;

	ray.origin = o;
	ray.d_unit = vunit(d);
	return (ray);
}

t_vector	ray_at(t_ray *ray, double t)
{
	t_vector	at;

	at = vplus(ray->origin, vmult(ray->d_unit, t));
	return (at);
}

t_vector	vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	vector_set(t_vector *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
