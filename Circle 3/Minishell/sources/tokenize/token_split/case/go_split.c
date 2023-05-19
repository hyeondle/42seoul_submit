/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:56:36 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 21:14:24 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**go_split(char **str, int i, int k)
{
	char	**temp;
	int		n;

	n = 0;
	temp = (char **)malloc(sizeof(char *) * (dtab_size(str) + 3));
	while (n < i)
	{
		temp[n] = str[n];
		n++;
	}
	temp[n] = ft_substr(str[i], 0, k);
	temp[n + 1] = deli_char(str[i][k]);
	temp[n + 2] = ft_substr(str[i], k + 1, ft_strlen(str[i]) - (k + 1));
	n++;
	while (str[n])
	{
		temp[n + 2] = str[n];
		n++;
	}
	temp[n + 2] = NULL;
	free(str[i]);
	free(str);
	return (temp);
}
