/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:54:10 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/06 18:16:41 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOF_H
# define FT_ATOF_H

# include "./trace.h"
# include <stdio.h>
# include <stdlib.h>

void	ft_atof_sign(char **str, t_bool *is_negative);
void	ft_atof_int(char **str, double *result);
void	ft_atof_fraction(char **str, double *result);
double	ft_atof(char *str);

#endif
