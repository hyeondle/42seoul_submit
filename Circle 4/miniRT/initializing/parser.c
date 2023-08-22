/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:22:08 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/19 21:38:53 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_setting	*init_setting(void)
{
	t_setting	*set;

	set = (t_setting *)malloc(sizeof(t_setting));
	if (!set)
	{
		printf("Error\nmalloc error\n");
		exit(1);
	}
	set->type = NULL;
	set->object = NULL;
	set->next = NULL;
	return (set);
}

void	parse(t_setting **set, char *line)
{
	t_setting	*temp;
	t_setting	*temp2;
	char		**info;

	temp = (*set);
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->type == NULL && temp->object == NULL)
		temp2 = *set;
	else
	{
		temp2 = init_setting();
		temp->next = temp2;
	}
	info = ft_split(line, ' ');
	if (info == NULL)
		p_exit("file error", 1);
	if (check_param(info) == FALSE)
		return (free_p_exit(info));
	temp2->type = ft_strdup(info[0]);
	temp2->object = object_set(info);
	free_info(info);
	if (temp->object == NULL)
		p_exit("file error", 1);
}

t_bool	check_acl(t_setting *set)
{
	t_bool		flag_a;
	t_bool		flag_c;
	t_bool		flag_l;
	t_setting	*node;

	flag_a = FALSE;
	flag_c = FALSE;
	flag_l = FALSE;
	node = set;
	while (node != NULL)
	{
		if (node->type[0] == 'A' && node->type[1] == '\0')
			flag_a = TRUE;
		if (node->type[0] == 'C' && node->type[1] == '\0')
			flag_c = TRUE;
		if (node->type[0] == 'L' && node->type[1] == '\0')
			flag_l = TRUE;
		node = node->next;
	}
	if (flag_a == TRUE && flag_c == TRUE && flag_l == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

t_setting	*parser(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_setting	*set;

	if (argc != 2)
		p_exit("input error", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		p_exit("wrong file", 1);
	set = init_setting();
	line = get_next_line(fd);
	if (line == NULL)
		p_exit("empty file.", 1);
	while (line != NULL)
	{
		parse(&set, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (check_acl(set) == FALSE)
		p_exit("file must have A,C,L.", 1);
	return (set);
}
