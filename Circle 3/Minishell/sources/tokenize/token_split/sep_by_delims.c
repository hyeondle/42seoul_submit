/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_by_delims.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:13:06 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 08:55:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**over_2_delims(char **str, int i, int k)
{
	char	**temp;
	int		j;

	j = k;
	if (k == 0)
	{
		while (str[i][j] == str[i][k])
			j++;
		if (str[i][j] != '\0')
			temp = token_split_case_no_front_over_delim(str, i, k, j);
		else
			return (str);
	}
	else
	{
		while (str[i][j] == str[i][k])
			j++;
		if (str[i][j] == '\0')
			temp = token_split_case_no_back_over_delim(str, i, k, j);
		else
			temp = go_split_over_delim(str, i, k, j);
	}
	return (temp);
}
