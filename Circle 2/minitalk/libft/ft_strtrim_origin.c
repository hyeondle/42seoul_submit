/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:13 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/12 12:59:53 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen4(const char *str);
static size_t	check_size_start(char const *s, char const *set);
static size_t	check_size_end(char const *s, char const *set);
static size_t	get_mal_size(char const *s1, char const *set);

static size_t	check_size_start(char const *s, char const *set)
{
	size_t	c;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && i == j)
	{
		c = 0;
		while (set[c] != '\0')
		{
			if (s[i] == set[c])
				j++;
			c++;
		}
		i++;
	}
	return (j);
}

static size_t	check_size_end(char const *s, char const *set)
{
	size_t	c;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen4(s);
	j = 0;
	k = 0;
	while (k == j && !(s == 0))
	{
		c = 0;
		while (set[c] != '\0')
		{
			if (s[i - 1] == set[c])
				j++;
			c++;
		}
		k++;
		i--;
	}
	return (j);
}

static size_t	ft_strlen4(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static size_t	get_mal_size(char const *s1, char const *set)
{
	size_t	ch_start;
	size_t	ch_end;
	size_t	i;
	size_t	mal_size;

	ch_start = check_size_start(s1, set);
	ch_end = check_size_end(s1, set);
	i = ft_strlen4(s1);
	if ((ch_start + ch_end) > i)
		mal_size = i + 1;
	else
		mal_size = i - (ch_start + ch_end) + 1;
	return (mal_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	mal_size;
	size_t	ch_start;
	size_t	i;
	char	*str;

	mal_size = get_mal_size(s1, set);
	str = (char *)malloc(sizeof(char) * (mal_size));
	if (!str)
		return (NULL);
	if (!s1)
	{
		str = 0;
		return (str);
	}
	i = 0;
	ch_start = check_size_start(s1, set);
	while (i < mal_size)
	{
		str[i] = s1[ch_start + i];
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}
