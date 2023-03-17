/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:09:45 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:56:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (ft_strlen((char *)src) + size);
	else
	{
		i = 0;
		while (len_dest + i + 1 < size && src[i] != '\0')
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
		return (len_dest + ft_strlen((char *)src));
	}
}
