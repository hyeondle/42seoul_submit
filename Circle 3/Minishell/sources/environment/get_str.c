/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:04:05 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 09:04:37 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_value(const char *str)
{
	char	*value;
	int		i;
	int		j;

	i = ft_strnlen(str, '=');
	value = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!value)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		value[j] = str[i];
		j++;
		i++;
	}
	value[j] = '\0';
	return (value);
}

char	*get_key(const char *str)
{
	char	*key;
	int		i;
	int		j;

	i = ft_strnlen(str, '=');
	key = (char *)malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	j = 0;
	while (j < i)
	{
		key[j] = str[j];
		j++;
	}
	key[j] = '\0';
	return (key);
}
