/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:57:18 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/03 12:02:17 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if str ended w/ opened quote, returns itself. else, returns w/ '\n'
#include "../../includes/minishell.h"

char	*check_input_add(char *additional)
{
	int		i;
	char	*temp;

	i = input_check(additional);
	if (i == 1)
		temp = ft_strjoin(additional, "\n");
	else
		return (additional);
	return (temp);
}
