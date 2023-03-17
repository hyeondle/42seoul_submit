/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:10:37 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:31:09 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	addscale(int keycode, t_base *base)
{
	if (keycode == 116)
		base->view->scale += 1;
	if (keycode == 121)
		base->view->scale -= 1;
	draw_image(base->map, base);
}

void	moving(int keycode, t_base *base)
{
	if (keycode == 123)
		base->view->offset_x -= 10;
	else if (keycode == 124)
		base->view->offset_x += 10;
	else if (keycode == 126)
		base->view->offset_y -= 10;
	else if (keycode == 125)
		base->view->offset_y += 10;
	draw_image(base->map, base);
}

void	rotate(int keycode, t_base *base)
{
	if (keycode == 12)
		base->view->theta_x += M_PI / 180;
	if (keycode == 13)
		base->view->theta_x -= M_PI / 180;
	if (keycode == 0)
		base->view->theta_y += M_PI / 180;
	if (keycode == 1)
		base->view->theta_y -= M_PI / 180;
	if (keycode == 6)
		base->view->theta_z += M_PI / 180;
	if (keycode == 7)
		base->view->theta_z -= M_PI / 180;
	draw_image(base->map, base);
}

void	modify_z(int keycode, t_base *base)
{
	if (keycode == 27)
		base->view->z_div_num -= 1;
	if (keycode == 24)
		base->view->z_div_num += 1;
	draw_image(base->map, base);
}
