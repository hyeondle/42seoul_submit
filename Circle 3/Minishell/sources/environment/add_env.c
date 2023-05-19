/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:40:37 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 13:11:58 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	go_update_env(t_env_list **env, const char *key_value_pair, \
							t_setting **set)
{
	char	*value;
	char	*key;
	char	*c_key;
	int		i;

	free((*env)->env.value);
	value = get_value(key_value_pair);
	(*env)->env.value = value;
	i = 0;
	key = get_key(key_value_pair);
	while ((*set)->envp[i])
	{
		c_key = get_key((*set)->envp[i]);
		if (ft_strcmp(key, c_key) == 0)
		{
			free((*set)->envp[i]);
			(*set)->envp[i] = ft_strdup(key_value_pair);
			free(c_key);
			return ;
		}
		free(c_key);
		i++;
	}
}

int	is_key_valid(const char *str, t_setting **set)
{
	char	*key;
	int		i;

	key = get_key(str);
	i = 0;
	while (key[i])
	{
		if (!((key[i] > 47 && key[i] < 58) || (key[i] > 64 && key[i] < 91) \
		|| (key[i] > 96 && key[i] < 123) || key[i] == 95))
		{
			report_error(str, set);
			free(key);
			return (1);
		}
		i++;
	}
	free(key);
	return (0);
}

static int	already_exist(t_env_list **env, const char *key_value_pair, \
						t_setting **set)
{
	t_env_list	*current;
	char		*key;

	current = *env;
	key = get_key(key_value_pair);
	while (current)
	{
		if (ft_strcmp((current->env.key), key) == 0)
		{
			go_update_env(&current, key_value_pair, set);
			free(key);
			return (1);
		}
		current = current->next;
	}
	free(key);
	return (0);
}

int	add_env(t_env_list **env, const char *key_value_pair, t_setting **set)
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
	if (is_key_valid(key_value_pair, set))
		return (0);
	if (already_exist(env, key_value_pair, set))
		return (0);
	add_env_envp(set, key_value_pair);
	new_node->env.key = ft_strndup(key_value_pair, equal_sign - key_value_pair);
	new_node->env.value = ft_strdup(equal_sign + 1);
	new_node->next = *env;
	*env = new_node;
	return (0);
}
