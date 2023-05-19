/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_case_no_back.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:58:11 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:58:37 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**token_split_case_no_back(char **str, int i, int k)
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
	temp[n + 1] = deli_char(str[i][k]);
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
