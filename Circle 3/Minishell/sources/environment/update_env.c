/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:28:09 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 01:29:26 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	update_env(t_env_list *env, const char *key, const char *new_value)
{
	t_env_list	*current;

	current = env;
	while (current)
	{
		if (ft_strcmp(current->env.key, key) == 0)
		{
			free(current->env.value);
			current->env.value = ft_strdup(new_value);
			return (0);
		}
		current = current->next;
	}
	return (-1);
}
