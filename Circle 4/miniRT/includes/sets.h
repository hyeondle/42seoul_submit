/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:09:14 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:21:18 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H

# define KEY_PRESS		2
# define DESTROY_NOTIFY	17

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_ESC		53
# define KEY_Q			12
# define KEY_E			14

# define KEY_UP 		126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define KEY_I			34

# include "./vector.h"
# include "./trace.h"

typedef struct s_ambient2
{
	double		ratio;
	t_vector	color;
}				t_ambient2;

typedef struct s_camera2
{
	t_vector	origin;
	t_vector	orientation;
	double		fov;
}				t_camera2;

typedef struct s_light2
{
	t_vector	point;
	double		brightness;
	t_vector	color;
}				t_light2;

typedef struct s_sphere2
{
	t_vector	origin;
	double		diameter;
	t_vector	color;
}				t_sphere2;

typedef struct s_plane2
{
	t_vector	point;
	t_vector	normal;
	t_vector	color;
}				t_plane2;

typedef struct s_cylinder2
{
	t_vector	origin;
	t_vector	axis;
	double		diameter;
	double		height;
	t_vector	color;
}				t_cylinder2;

typedef struct s_setting
{
	char				*type;
	void				*object;
	struct s_setting	*next;
}						t_setting;

typedef struct s_base
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_base;

int	ft_abs(int num);

#endif