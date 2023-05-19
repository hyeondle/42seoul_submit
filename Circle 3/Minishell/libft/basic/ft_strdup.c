/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:35:25 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 21:14:24 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		index;
	char	*tab;
	int		index2;

	index = 0;
	index2 = 0;
	while (src[index2])
		index2++;
	tab = (char *)malloc(index2 * sizeof(char) + 1);
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
