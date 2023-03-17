/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:34:23 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 17:10:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*make_table_with_split(char **argv)
{
	int		*table;
	int		argc;
	char	**nums;
	char	*lines;

	lines = ft_strjoin("a ", argv[1]);
	nums = ft_split(lines, ' ');
	argc = 0;
	while (nums[argc])
		argc++;
	table = make_table(argc, nums);
	return (table);
}

int	*make_table(int argc, char **argv)
{
	int	*table;
	int	i;
	int	j;

	table = (int *)malloc(sizeof(int) * (argc - 1));
	if (!table)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		j = ft_isnumber(argv[i + 1]);
		if (j != 1)
		{
			free(table);
			goterror();
		}
		table[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	check_table(table, argc);
	return (table);
}

t_list	*make_stack(int *table, t_list *b_stack, int argc)
{
	t_list	*first;
	t_list	*second;
	int		i;

	first = ft_lstnew(table[0]);
	b_stack = first;
	i = 1;
	while (i < argc - 1)
	{
		second = ft_lstnew(table[i]);
		ft_lstadd_back(&first, second);
		first = second;
		i++;
	}
	return (b_stack);
}
