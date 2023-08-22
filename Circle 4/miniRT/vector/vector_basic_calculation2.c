/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_calculation2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:53:28 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:26:59 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	vplus_2(t_vector v, double x, double y, double z)
{
	t_vector	v_;

	v_.x = v.x + x;
	v_.y = v.y + y;
	v_.z = v.z + z;
	return (v_);
}

t_vector	vminus_2(t_vector v, double x, double y, double z)
{
	t_vector	v_;

	v_.x = v.x - x;
	v_.y = v.y - y;
	v_.z = v.z - z;
	return (v_);
}

t_vector	vmult_2(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}

t_vector	vmin(t_vector vec1, t_vector vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}
