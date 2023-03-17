/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:16 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:24:56 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fcntl.h, unistd.h for open, read, write, close
stdlib.h for malloc, free
stdio.h for perror, strerror
stdlib.h for exit
math.h for rotate / use M_PI, cos, sin
*/

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "errormsg.h"
# include "libft.h"

# define WIDTH		1920
# define HEIGHT		1080
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define WHITE		0x00FFFFFF
# define BLACK		0x00000000

// for calculating colors
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	double	per;
}			t_color;

// for calculating inc of x,y (to draw line)
typedef struct s_incs
{
	float	x;
	float	y;
	float	incx;
	float	incy;
	float	total_distance;
}			t_incs;

// z point info (connected list)
typedef struct s_dotz
{
	int				z;
	unsigned int	color;
	struct s_dotz	*next;
}					t_dotz;

// get each point (use when read & parse the map)
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

// map info
// includes map's x, y value, each point's z value and value z's range)
typedef struct s_map
{
	int	map_width;
	int	map_height;
	int	z_min;
	int	z_max;
	int	z_range;
	int	*z_point_array;
	int	*z_color_array;
}		t_map;

// view point
// includes theta of each x, y, z and take offset of viewpoint(for moving x, y)
typedef struct s_view
{
	float	scale;
	double	theta_x;
	double	theta_y;
	double	theta_z;
	int		offset_x;
	int		offset_y;
	float	z_div_num;
	int		projection;
}			t_view;

// base elements for using fdf
typedef struct s_base
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_map	*map;
	t_view	*view;
}			t_base;

// main
int		goterror(char *errortype);
void	get_map(const int fd, t_dotz **dotz_stack, t_map *map);
void	set_map(t_dotz **dotz_stack, t_map *map);
void	draw_image(t_map *map, t_base *base);
t_point	project(t_point p, t_base *base);
int		color_set(int x, t_point p, t_point n);
t_view	*view_init(t_base *base);
t_map	*map_init(void);
t_base	*base_init(t_map *map);

//events
void	event(t_base *base);
void	win_exit(t_base *base);
void	change_projection(int keycode, t_base *base);
void	addscale(int keycode, t_base *base);
void	moving(int keycode, t_base *base);
void	rotate(int keycode, t_base *base);
void	modify_z(int keycode, t_base *base);

//utils
int		ft_number_base(char c, int base);
int		ft_isnumber(char *str, int base);
int		ft_atoi(const char *str);
t_point	init_delta(t_point p, t_point n);
t_point	init_flag(t_point p, t_point n);

#endif
