/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:47:29 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 00:55:16 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env(t_env_list	*env)
{
	t_env_list	*current;
	t_env_list	*next;

	current = env;
	while (current)
	{
		next = current->next;
		free(current->env.key);
		free(current->env.value);
		free(current);
		current = next;
	}
}
