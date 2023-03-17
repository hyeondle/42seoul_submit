/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:14:00 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 12:23:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	goterror(char *errortype)
{
	perror(errortype);
	exit(1);
}

int	check_valid_type(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		i++;
	i--;
	if (name[i] == 'f' && name[i - 1] == 'd' && name[i - 2] == 'f' \
		&& name[i - 3] == '.')
		return (0);
	else
		goterror(ERR_FILE_TYPE);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_base	*base;
	t_map	*map;
	t_dotz	*dotz_stack;

	dotz_stack = NULL;
	if (argc == 2)
	{
		check_valid_type(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			goterror(ERR_FD);
		map = map_init();
		get_map(fd, &dotz_stack, map);
		base = base_init(map);
		set_map(&dotz_stack, map);
		base->view = view_init(base);
		draw_image(base->map, base);
		event(base);
		mlx_loop(base->mlx);
	}
	goterror(ERR_MAIN_INPUT);
	return (0);
}
