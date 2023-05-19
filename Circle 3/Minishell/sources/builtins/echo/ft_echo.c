/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:48:28 by Linsio            #+#    #+#             */
/*   Updated: 2023/05/05 23:02:10 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <unistd.h>

static int	ft_echo_with_option_n(char **inputs)
{
	int	i;

	i = 2;
	if (inputs[i] == NULL || *(inputs[i]) == '\0')
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	while (inputs[i])
	{
		if (!inputs[i + 1])
		{
			ft_putstr_fd(inputs[i], STDOUT_FILENO);
			break ;
		}
		ft_putstr_fd(inputs[i], STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	return (0);
}

static void	ft_echo_putstr(int i, char **inputs)
{
	while (inputs[i])
	{
		if (!inputs[i + 1])
		{
			ft_putstr_fd(inputs[i], STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			break ;
		}
		ft_putstr_fd(inputs[i], STDOUT_FILENO);
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
}

int	ft_echo(char **inputs, t_setting **set)
{
	int	i;

	i = 1;
	if (inputs[i] == NULL || *(inputs[i]) == '\0')
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		(*set)->last_exit_status = 1;
		return (1);
	}
	if (ft_strcmp(inputs[i], "-n") == 0)
		ft_echo_with_option_n(inputs);
	else
	{
		ft_echo_putstr(i, inputs);
	}
	(*set)->last_exit_status = 0;
	return (0);
}
