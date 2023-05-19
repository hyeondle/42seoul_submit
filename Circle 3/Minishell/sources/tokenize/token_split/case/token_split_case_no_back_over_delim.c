/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_case_no_back_over_delim.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:30:26 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 08:54:43 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**token_split_case_no_back_over_delim(char **str, int i, int k, int j)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 2));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = ft_substr(str[i], 0, k);
	temp[n + 1] = deli_char_over_delim(str[i][k], k, j);
	n++;
	while (str[n])
	{
		temp[n + 1] = str[n];
		n++;
	}
	temp[n + 1] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}
