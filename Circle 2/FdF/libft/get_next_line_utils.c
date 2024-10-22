/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:06:54 by hyeondle          #+#    #+#             */
/*   Updated: 2022/09/24 18:14:10 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		c;

	if (!s)
		return (NULL);
	i = 0;
	c = ft_strlen(s);
	if (start > c)
		len = 0;
	if (len > c)
		len = c;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = ((char *)s)[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup2(char *src)
{
	int		index;
	char	*tab;
	int		index2;

	index = 0;
	index2 = 0;
	while (src[index2])
		index2++;
	tab = (char *)malloc(sizeof(char) * (index2 + 1));
	if (!tab)
		return (0);
	while (src[index])
	{
		tab[index] = ((char *)src)[index];
		index++;
	}
	tab[index] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;
	int		c;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	c = 0;
	joined = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!joined)
		return (NULL);
	while (c != i)
	{
		joined[c] = s1[c];
		c++;
	}
	c = 0;
	while (c != j)
	{
		joined[i + c] = s2[c];
		c++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*hay;

	i = 0;
	hay = (char *)str;
	while (hay[i] != (char)c)
	{
		if (hay[i] == '\0')
			return (0);
		i++;
	}
	return (&hay[i]);
}
