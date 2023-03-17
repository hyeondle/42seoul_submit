/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:11 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/28 15:44:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen3(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joined = (char *)malloc(sizeof(char) * (ft_strlen3(s1) \
			+ ft_strlen3(s2) + 1));
	if (!joined)
		return (NULL);
	while (i != ft_strlen3(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	while (j != ft_strlen3(s2))
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
