/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_case_no_front.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:58:51 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/27 13:28:40 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	**token_split_case_no_front(char **str, int i, int k)
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
	temp[n] = deli_char(str[i][k]);
	temp[n + 1] = ft_substr(str[i], k + 1, ft_strlen(str[i]) - (k + 1));
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
