/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:30:19 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:30:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_key(char *str, int i)
{
	int		k;
	int		j;
	char	*key;

	k = i + 1;
	j = 0;
	while (str[k] != '$' && str[k] != '\0' && str[k] != '\"' \
	&& str[k] != ' ' && str[k] != '\'' && ((str[k] > 47 && str[k] < 58) \
	|| (str[k] > 64 && str[k] < 91) || (str[k] > 96 && str[k] < 123)))
		k++;
	if (str[i + 1] == '?')
		k = i + 2;
	key = (char *)malloc(sizeof(char) * (k - i));
	if (!key)
		return (NULL);
	while (i < k)
	{
		key[j] = str[i + 1];
		i++;
		j++;
	}
	key[j - 1] = '\0';
	return (key);
}
