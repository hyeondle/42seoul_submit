/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:49:09 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/19 21:40:08 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_atof.h"

void	ft_atof_sign(char **str, t_bool *is_negative)
{
	while (**str == ' ')
		(*str)++;
	*is_negative = FALSE;
	if (**str == '-')
	{
		*is_negative = TRUE;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

void	ft_atof_int(char **str, double *result)
{
	*result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		*result = *result * 10.0 + (**str - '0');
		(*str)++;
	}
}

void	ft_atof_fraction(char **str, double *result)
{
	double	fraction;

	fraction = 0.1;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			*result += (**str - '0') * fraction;
			fraction *= 0.1;
			(*str)++;
		}
	}
	else if (**str != '\0' && **str != '\n')
	{
		printf("Error\narguments error\n");
		exit(1);
	}
}

double	ft_atof(char *str)
{
	t_bool	is_negative;
	double	result;

	if (str == NULL)
		return (0);
	ft_atof_sign(&str, &is_negative);
	ft_atof_int(&str, &result);
	ft_atof_fraction(&str, &result);
	if (is_negative == TRUE)
		result *= -1;
	return (result);
}
