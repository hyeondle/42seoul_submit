/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:24:02 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 01:38:21 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	del_env(t_env *env)
{
	free(env->key);
	free(env->value);
	env->key = NULL;
	env->value = NULL;
	free(env);
	env = NULL;
}

void	free_elist(t_env_list **envs)
{
	t_env_list	*temp;

	while (*envs)
	{
		temp = (*envs)->next;
		del_env((&(*envs)->env));
		*envs = temp;
	}
	*envs = NULL;
}

void	free_hlist(t_history **hist)
{
	t_history	*temp;

	while (*hist)
	{
		temp = (*hist)->next;
		free(*hist);
		*hist = temp;
	}
	*hist = NULL;
}

void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		envp[i] = NULL;
		i++;
	}
	free(envp);
}

void	free_settings(t_setting *set)
{
	free_envp(set->envp);
	free_hlist(&(set->s_history));
	free_hlist(&(set->l_history));
	free_elist(&(set->env_list));
	free(set);
	set = NULL;
}
