/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:31:31 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/30 16:58:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*table;
	t_list	*a;
	t_list	*b;
	int		t_argc;

	t_argc = argc;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		table = make_table_with_split(argv);
		t_argc = tab_length(argv[1]);
	}
	else
		table = make_table(t_argc, argv);
	a = NULL;
	b = NULL;
	a = make_stack(table, a, t_argc);
	find_case_and_sort(t_argc, &a, &b, &table);
	free(table);
	free_stack(&a);
	return (0);
}
