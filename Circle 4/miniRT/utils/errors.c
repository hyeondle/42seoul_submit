/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:23:42 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/19 21:40:01 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"

void	p_exit(char *str, int code)
{
	printf("Error\n%s\n", str);
	exit(code);
}