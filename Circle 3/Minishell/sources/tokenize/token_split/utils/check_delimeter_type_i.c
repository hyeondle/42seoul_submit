/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimeter_type_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:54:04 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 20:43:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	check_delimeter_type_i(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
		}
		if (token_check(str[i]))
			return (i);
		i++;
	}
	return (0);
}
