/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:35:56 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:32:38 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	add_envd(t_env_list **env, const char *key_value_pair)
{
	t_env_list	*new_node;
	char		*equal_sign;

	new_node = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new_node)
		return (1);
	equal_sign = ft_strchr(key_value_pair, '=');
	if (!equal_sign)
	{
		free(new_node);
		return (1);
	}
	new_node->env.key = ft_strndup(key_value_pair, equal_sign - key_value_pair);
	new_node->env.value = ft_strdup(equal_sign + 1);
	new_node->next = *env;
	*env = new_node;
	return (0);
}

void	init_env(char **envp, t_setting **set)
{
	t_env_list	*head;
	int			i;

	i = 0;
	while (envp[i])
		i++;
	(*set)->envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		(*set)->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	(*set)->envp[i] = NULL;
	head = NULL;
	i = 0;
	while (envp[i])
	{
		add_envd(&head, envp[i]);
		i++;
	}
	(*set)->env_list = head;
}
