/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimeter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:53:22 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 20:43:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	del_size(char *str, int i, int size)
{
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		if (token_check(str[i]) && str[i] != '\0')
			size++;
		if (str[i] != '\0')
			i++;
	}
	return (size);
}

int	check_delimeter(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	return (del_size(str, i, size));
}
