/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:18 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:16:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "map.h"
# include "trace.h"
# include "sets.h"

void	locate_pixel(t_base *base, int x, int y, int color);
void	write_color(t_vector pixel_color, t_base *base, int x, int y);
void	draw(t_map *map, t_base *base);

#endif