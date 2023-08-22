/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product_calculation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:55:10 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/19 21:40:16 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include <stdio.h>
#include <stdlib.h>

double	vdot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	vcross(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vector	vunit(t_vector v)
{
	t_vector	v_;
	double		length;

	length = vlength(v);
	if (length == 0)
	{
		printf("Error\n0 devide\n");
		exit(0);
	}
	v_.x = v.x / length;
	v_.y = v.y / length;
	v_.z = v.z / length;
	return (v_);
}
