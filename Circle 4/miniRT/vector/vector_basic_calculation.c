/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_calculation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:53:28 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:27:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	vplus(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vector	vminus(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vector	vmult(t_vector v, double t)
{
	t_vector	v_;

	v_.x = v.x * t;
	v_.y = v.y * t;
	v_.z = v.z * t;
	return (v_);
}

t_vector	vdivide(t_vector v, double t)
{
	t_vector	v_;

	if (t == 0)
		return (vector(0, 0, 0));
	v_.x = v.x * (1.0 / t);
	v_.y = v.y * (1.0 / t);
	v_.z = v.z * (1.0 / t);
	return (v_);
}
