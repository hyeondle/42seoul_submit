/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:09:26 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:10:17 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	onetime_event(int keycode, t_base *base)
{
	if (keycode == 53)
		win_exit(base);
	if (keycode == 83 || keycode == 85 || keycode == 86 || \
		keycode == 87 || keycode == 88)
		change_projection(keycode, base);
	return (0);
}

int	hooking_event(int keycode, t_base *base)
{
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		moving(keycode, base);
	if (keycode == 116 || keycode == 121)
		addscale(keycode, base);
	if (keycode == 12 || keycode == 13 || keycode == 0 || \
		keycode == 1 || keycode == 6 || keycode == 7)
		rotate(keycode, base);
	if (keycode == 27 || keycode == 24)
		modify_z(keycode, base);
	return (0);
}

void	event(t_base *base)
{
	mlx_key_hook(base->win, onetime_event, base);
	mlx_hook(base->win, 2, 2, hooking_event, base);
}
