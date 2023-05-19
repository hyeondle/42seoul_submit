/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:55:00 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/05 22:44:04 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	execute_check(char *o)
{
	if (ft_strcmp(o, "cd") == 0)
		return (3);
	else if (ft_strcmp(o, "exit") == 0)
		return (5);
	else if (ft_strcmp(o, "export") == 0)
		return (6);
	else if (ft_strcmp(o, "pwd") == 0)
		return (7);
	else if (ft_strcmp(o, "unset") == 0)
		return (8);
	return (0);
}

int	go_execute(char **inputs, t_setting **set, char *o)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(o, "echo") == 0)
		flag = ft_echo(inputs, set);
	if (ft_strcmp(o, "cd") == 0)
		flag = ft_cd(inputs, set);
	else if (ft_strcmp(o, "env") == 0)
		flag = ft_env((*set)->envp, set);
	else if (ft_strcmp(o, "exit") == 0)
		flag = ft_exit(inputs, set);
	else if (ft_strcmp(o, "export") == 0)
		flag = ft_export(set, inputs);
	else if (ft_strcmp(o, "pwd") == 0)
		flag = ft_pwd();
	else if (ft_strcmp(o, "unset") == 0)
		flag = ft_unset(set, inputs);
	return (flag);
}
