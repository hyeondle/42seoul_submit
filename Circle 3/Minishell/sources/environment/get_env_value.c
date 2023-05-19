/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:56 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 07:57:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_env_list *env, const char *key, t_setting **set)
{
	t_env_list	*current;

	current = env;
	if (!key)
		return (NULL);
	else if (key[0] == '?')
		return (ft_itoa((*set)->last_exit_status));
	while (current)
	{
		if (ft_strcmp(current->env.key, key) == 0)
		{
			return (current->env.value);
		}
		current = current->next;
	}
	return (NULL);
}
