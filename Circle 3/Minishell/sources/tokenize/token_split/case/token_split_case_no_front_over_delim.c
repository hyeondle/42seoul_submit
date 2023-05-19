/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_case_no_front_over_delim.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:24:00 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 08:54:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**token_split_case_no_front_over_delim(char **str, int i, int k, int j)
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
	temp[n] = deli_char_over_delim(str[i][k], k, j);
	temp[n + 1] = ft_substr(str[i], j, ft_strlen(str[i]) - (j));
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
