/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:05:11 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:56:11 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
