/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_onetime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:11:34 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:25:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_exit(t_base *base)
{
	mlx_destroy_window(base->mlx, base->win);
	exit(1);
}

void	change_viewpoint(int keycode, t_base *base)
{
	if (keycode == 86)
	{
		base->view->z_div_num = 0;
		base->view->theta_x = M_PI / 2;
		base->view->theta_y = 0;
		base->view->theta_z = 0;
		base->view->projection = 2;
	}
	if (keycode == 87)
	{
		base->view->z_div_num = 0;
		base->view->theta_x = 0;
		base->view->theta_y = M_PI / 2;
		base->view->theta_z = 0;
		base->view->projection = 2;
	}
	if (keycode == 88)
	{
		base->view->z_div_num = 0;
		base->view->theta_x = 0;
		base->view->theta_y = 0;
		base->view->theta_z = 0;
		base->view->projection = 2;
	}
}

void	change_projection(int keycode, t_base *base)
{
	if (keycode == 83)
	{
		base->view->z_div_num = 0;
		base->view->theta_x = 0;
		base->view->theta_y = 0;
		base->view->theta_z = 0;
		base->view->projection = 1;
	}
	if (keycode == 85)
	{
		base->view->z_div_num = 0;
		base->view->theta_x = 0;
		base->view->theta_y = 0;
		base->view->theta_z = 0;
		base->view->projection = 3;
	}
	if (keycode == 86 || keycode == 87 || keycode == 88)
		change_viewpoint(keycode, base);
	draw_image(base->map, base);
}
