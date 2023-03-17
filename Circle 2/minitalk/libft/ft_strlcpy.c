/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:15:17 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:57:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	temp;

	count = 0;
	temp = ft_strlen((char *)src);
	if (!dst || !src)
		return (0);
	while (count < temp && count + 1 < dstsize)
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize > 0)
		dst[count] = '\0';
	return (temp);
}
