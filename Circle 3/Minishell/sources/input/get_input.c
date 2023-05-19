/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:33:48 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:23:27 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static t_bool	forced_terminated(char *input)
// {
// 	int	i;

// 	i = 0;
// 	if (!input)
// 	{
// 		printf("unexpected EOF while looking for matching `\n");
// 		printf("syntax error: unexpected end of file\n");
// 		free(input);
// 		input = NULL;
// 		return (0);
// 	}
// 	return (1);
// }

char	*join_input(char *input, char *input_add)
{
	char	*temp;

	temp = input;
	input = ft_strjoin(input, input_add);
	input = check_input_add(input);
	free(input_add);
	free(temp);
	return (input);
}

char	*get_input(t_setting **set)
{
	char	*input;
	int		i;

	input = readline("minishell> ");
	if (!input)
		ft_exit(NULL, set);
	i = input_check(input);
	if (i == 1)
		printf("syntax error: unexpected end of file\n");
	return (input);
}
