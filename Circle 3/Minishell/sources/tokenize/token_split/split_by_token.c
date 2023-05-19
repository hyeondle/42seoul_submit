/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:49:06 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:34:34 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	**split_case(char **str, int i)
{
	int	k;

	k = 0;
	k = check_delimeter_type_i(str[i]);
	if (str[i][k + 1] != '\0' && token_check(str[i][k + 1]) == 1)
		return (over_2_delims(str, i, k));
	else
		return (split_by_case(str, i, k));
}

static int	split_case_i(char **str, int i)
{
	int	k;

	k = 0;
	k = check_delimeter_type_i(str[i]);
	if (str[i][k + 1] != '\0' && token_check(str[i][k + 1]) == 1)
		return (over_2_delims_i(k));
	else
		return (split_case_index_check(str, i, k));
}

char	**split_by_token(char **str)
{
	char	**temp_2;
	int		i;
	int		c;

	i = 0;
	temp_2 = str;
	while (temp_2[i])
	{
		if (check_delimeter(temp_2[i]))
		{
			temp_2 = split_case(temp_2, i);
			c = split_case_i(temp_2, i);
			i = i + c;
		}
		else
			i++;
	}
	return (temp_2);
}
