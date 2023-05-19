/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:10:13 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:58:17 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ch_start;
	size_t	ch_end;
	char	*tab;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	ch_start = 0;
	ch_end = ft_strlen(s1);
	while (s1[ch_start] && ft_strchr(set, s1[ch_start]))
		ch_start++;
	while (s1[ch_end - 1] && ft_strchr(set, s1[ch_end - 1]))
	{
		if (ch_end - 1 < 1)
			break ;
		ch_end--;
	}
	if (ch_start > ch_end)
		return (ft_strdup(""));
	tab = (char *)malloc(sizeof(char) * (ch_end - ch_start + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1 + ch_start, ch_end - ch_start + 1);
	return (tab);
}
