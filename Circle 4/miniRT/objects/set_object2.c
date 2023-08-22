/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:25:08 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/19 21:39:40 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/set_object.h"

t_vector	mv(char *dot)
{
	char		**tab;
	t_vector	rvec;

	tab = ft_split(dot, ',');
	if (!tab || !tab[0] || !tab[1] || !tab[2] || tab[3])
	{
		printf("Error\ninvalid input\n");
		exit(1);
	}
	rvec = vector(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	free_tab(tab);
	return (rvec);
}

t_ambient2	*i_ambient(char **info)
{
	t_ambient2	*ambient;

	ambient = (t_ambient2 *)malloc(sizeof(t_ambient2));
	ambient->ratio = ft_atof(info[1]);
	ambient->color = mv(info[2]);
	return (ambient);
}

t_camera2	*i_camera(char **info)
{
	t_camera2	*camera;

	camera = (t_camera2 *)malloc(sizeof(t_camera2));
	camera->origin = mv(info[1]);
	camera->orientation = mv(info[2]);
	camera->fov = ft_atof(info[3]);
	return (camera);
}
