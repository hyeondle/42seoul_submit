/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_void_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:31 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:44 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_void_pointer(va_list conv)
{
	int					printed_leng;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(conv, void *);
	write(1, "0x", 2);
	printed_leng = 2 + ft_putnbr_base(pointer, "0123456789abcdef");
	return (printed_leng);
}
