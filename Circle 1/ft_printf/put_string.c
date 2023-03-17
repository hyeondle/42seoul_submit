/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:22:36 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_string(va_list conv)
{
	int		i;
	char	*s;

	s = va_arg(conv, char *);
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}
