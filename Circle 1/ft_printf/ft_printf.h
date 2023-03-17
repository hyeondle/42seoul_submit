/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:09:55 by hyeondle          #+#    #+#             */
/*   Updated: 2022/08/25 13:56:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str_m, ...);
int	ft_strlen(const char *str);
int	ft_putnbr_fd(long long n, int d);
int	put_char(va_list conv);
int	put_decimal(va_list conv);
int	put_string(va_list conv);
int	put_unsigned_int(va_list conv, int type);
int	put_void_pointer(va_list conv);
int	ft_putnbr_base(unsigned long long nbr, char *base);

#endif
