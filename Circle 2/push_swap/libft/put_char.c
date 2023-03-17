/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:19:33 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(va_list conv)
{
	char	temp;

	temp = (char)va_arg(conv, int);
	write(1, &temp, 1);
	return (1);
}
