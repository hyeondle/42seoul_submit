/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:25:54 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 14:10:22 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read&parse the map for get basic map info
#include "fdf.h"

// free all elements
void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

// make stacks by using connected list (modify ft_addlist)
t_dotz	*make_stack(char *s)
{
	t_dotz	*new_stack;
	char	**elements;

	new_stack = (t_dotz *)malloc(sizeof(t_dotz));
	if (!new_stack)
		goterror(ERR_MALLOC);
	elements = ft_split(s, ',');
	if (!elements)
		goterror(ERR_PARSING_MAP);
	new_stack->z = ft_atoi(elements[0]);
	if (elements[1])
		new_stack->color = ft_isnumber(elements[1], 16);
	else
		new_stack->color = WHITE;
	new_stack->next = NULL;
	free_table(elements);
	return (new_stack);
}

// modified lstaddfront
void	push_new_stack(t_dotz **dotz_stack, t_dotz *new_element)
{
	if (dotz_stack)
	{
		if (new_element)
			new_element->next = *dotz_stack;
			*dotz_stack = new_element;
	}
}

// if line exist, make line as stack and connect
void	get_line(char **dotz_line, t_dotz **dotz_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*dotz_line)
	{
		if (*dotz_line == NULL)
			push_new_stack(dotz_stack, NULL);
		push_new_stack(dotz_stack, make_stack(*(dotz_line++)));
		width++;
	}
	if (map->map_height == 0)
		map->map_width = width;
	else if (map->map_width != width)
		goterror(ERR_MAP_MAKE);
}

// read line, make stack, again.. again.. till eof
void	get_map(const int fd, t_dotz **dotz_stack, t_map *map)
{
	char	*line;
	char	**dotz_line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		dotz_line = ft_split(line, ' ');
		if (!dotz_line)
			goterror(ERR_PARSING_MAP);
		get_line(dotz_line, dotz_stack, map);
		free_table(dotz_line);
		free(line);
		line = NULL;
		map->map_height++;
	}
	if (!(dotz_stack))
		goterror(ERR_MAP_MAKE);
}
