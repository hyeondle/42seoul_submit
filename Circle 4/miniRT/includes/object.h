/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:00:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:05:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "./vector.h"

typedef int	t_object_type;
# define LIGHT_POINT	0
# define SP				1
# define PL				2
# define CY				3
/*			object_list					*/
typedef struct s_object
{
	t_object_type	type;
	void			*element;
	t_vector		albedo;
	void			*next;
}				t_object;

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
	double		radius2;
}				t_sphere;

typedef struct s_light
{
	t_vector	origin;
	t_vector	color;
	double		brightness;
}				t_light;

typedef struct s_plane
{
	t_vector	origin;
	t_vector	normal;
}				t_plane;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	axis;
	double		radius;
	double		height;
}				t_cylinder;

/*			object_list_control			*/
t_object	*object(t_object_type type, void *element, t_vector albedo);
void		oadd(t_object **list, t_object *newo);
t_object	*olast(t_object *list);
/*			objects						*/
t_light		*light_point(t_vector origin, t_vector color, double brightness);
t_sphere	*sphere(t_vector center, double radius);
t_plane		*plane(t_vector origin, t_vector normal);
t_cylinder	*cylinder(t_vector origin, t_vector axis, \
						double radius, double height);

#endif
