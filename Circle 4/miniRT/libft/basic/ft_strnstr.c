/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:20:04 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:58:44 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[j] == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && (i + j) < len)
			j++;
		if (!s2[j])
			return (&((char *)s1)[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
