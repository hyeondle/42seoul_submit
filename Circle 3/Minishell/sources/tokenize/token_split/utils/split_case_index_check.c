/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_case_index_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:51:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/15 06:46:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	split_case_index_check(char **str, int i, int k)
{
	if (k == 0)
	{
		if (str[i][k + 1] != '\0')
			return (1);
		else
			return (1);
	}
	else
	{
		if (str[i][k + 1] == '\0')
			return (2);
		else
			return (2);
	}
}
