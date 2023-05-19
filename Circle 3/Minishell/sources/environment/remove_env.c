/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:50:27 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/15 00:31:59 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	remove_env(t_env_list **env, const char *key, t_setting **set)
{
	t_env_list	*current;
	t_env_list	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->env.key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			remove_env_envp(set, key);
			free(current->env.key);
			free(current->env.value);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (1);
}
