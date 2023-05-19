/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:47:04 by Linsio            #+#    #+#             */
/*   Updated: 2023/05/06 23:30:41 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	sort_env(char **s, int i)
{
	int	k;
	int	j;

	k = 0;
	while (k < i - 1)
	{
		j = 0;
		while (j < i - 1)
		{
			if (ft_strcmp(s[j], s[j + 1]) > 0)
				ft_swap(&s[j], &s[j + 1]);
			j++;
		}
		k++;
	}
	return ;
}

void	free_temp_env(char **temp_env)
{
	int	i;

	i = 0;
	while (temp_env[i])
	{
		free(temp_env[i]);
		temp_env[i] = NULL;
		i++;
	}
	free(temp_env);
	temp_env = NULL;
}

static void	export_with_no_input(char **envp)
{
	int		i;
	char	**temp_env;
	char	*str;

	i = 0;
	while (envp[i])
		i++;
	temp_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		temp_env[i] = ft_strdup(envp[i]);
		i++;
	}
	temp_env[i] = NULL;
	sort_env(temp_env, i);
	i = 0;
	while (temp_env[i])
	{
		str = make_export_str(temp_env[i]);
		ft_putstr_fd(str, STDOUT_FILENO);
		free(str);
		i++;
	}
	free_temp_env(temp_env);
}

int	ft_export(t_setting **set, char **inputs)
{
	int		i;

	i = 1;
	if (!inputs[1])
		export_with_no_input((*set)->envp);
	while (inputs[i])
	{
		if (check_pipe(inputs))
		{
			run_cmd(inputs, (*set)->envp, set);
			return (0);
		}
		else if (check_export_input(inputs[i]))
		{
			(*set)->last_exit_status = 1;
			report_error(inputs[i], set);
			return (1);
		}
		add_env(&((*set)->env_list), inputs[i], set);
		i++;
	}
	return (0);
}
