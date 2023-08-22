/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:50:36 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:14:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	d_unit;
}				t_ray;

/*			vector					*/
t_vector	vector(double x, double y, double z);
void		vector_set(t_vector *v, double x, double y, double z);
/*			ray						*/
t_ray		ray(t_vector o, t_vector d);
t_vector	ray_at(t_ray *ray, double t);
/*			basic_calculation		*/
t_vector	vplus(t_vector v1, t_vector v2);
t_vector	vminus(t_vector v1, t_vector v2);
t_vector	vmult(t_vector v, double t);
t_vector	vdivide(t_vector v, double t);
t_vector	vplus_2(t_vector v, double x, double y, double z);
t_vector	vminus_2(t_vector v, double x, double y, double z);
t_vector	vmult_2(t_vector v1, t_vector v2);
t_vector	vmin(t_vector vec1, t_vector vec2);
/*			vector_length		*/
double		vlength(t_vector v);
double		vlength_pow2(t_vector v);
/*			product_calculation		*/
double		vdot(t_vector v1, t_vector v2);
t_vector	vcross(t_vector v1, t_vector v2);
t_vector	vunit(t_vector v);

#endif