/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:48:45 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 06:38:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_unset(t_setting **set, char **inputs)
{
	int	i;

	i = 1;
	while (inputs[i])
	{
		remove_env(&((*set)->env_list), inputs[i], set);
		i++;
	}
	return (0);
}
