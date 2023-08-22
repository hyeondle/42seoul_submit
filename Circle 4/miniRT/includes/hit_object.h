/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:35:00 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/21 11:46:26 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_OBJECT_H
# define HIT_OBJECT_H

# include "./trace.h"

typedef struct s_calsphere
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
}	t_calsphere;

typedef struct s_calcylinder
{
	t_vector	oc;
	t_vector	top_centroid;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		hit_t;
	t_bool		hit;
	t_bool		cap_hit;
	t_vector	cap_normal;
}	t_calcylinder;

t_hit_record	record_init(void);
t_bool			hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_plane(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec);
void			hit_cylinder_set_info(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double t);
t_bool			hit_cylinder_cap_hit_bottom(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t);
t_bool			hit_cylinder_cap_hit_top(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t);
t_bool			hit_cylinder_cap_bottom(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t);
t_bool			hit_cylinder_cap_top(t_ray *ray, t_hit_record *rec, \
			t_cylinder *cy, double min_t);
t_bool			hit_cylinder_caps(t_object *obj, t_ray *ray, t_hit_record *rec);
void			hit_check(t_calcylinder *h, t_cylinder *cy, \
					t_hit_record *rec, t_ray *ray);
void			condition_check(t_calcylinder *h, t_cylinder *cy, \
						t_hit_record *rec, t_ray *ray);
void			set_rec_cylinder(t_calcylinder h, t_object *obj, \
			t_ray *ray, t_hit_record *rec);
t_bool			hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec);

#endif