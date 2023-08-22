/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:10:32 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/06 18:16:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OBJECT_H
# define SET_OBJECT_H

# include "./sets.h"
# include <stdlib.h>
# include "./ft_atof.h"
# include "./ft_free.h"
# include "../libft/basic/libft.h"

void		*object_set(char **info);
t_cylinder2	*i_cylinder(char **info);
t_plane2	*i_plane(char **info);
t_sphere2	*i_sphere(char **info);
t_light2	*i_light(char **info);
t_vector	mv(char *dot);
t_ambient2	*i_ambient(char **info);
t_camera2	*i_camera(char **info);

#endif