/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:49:06 by Linsio            #+#    #+#             */
/*   Updated: 2023/05/06 01:42:39 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <unistd.h>

static int	digit_check(char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		k = ft_isdigit(str[i]);
		if (k == 0)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				i++;
				continue ;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*get_err_msg(char *c1)
{
	char	*t1;
	char	*t2;

	t1 = ft_strjoin("exit: ", c1);
	t2 = ft_strjoin(t1, ": numeric argument required\n");
	free(t1);
	return (t2);
}

static void	exit_with_input(char **inputs, t_setting **set)
{
	int		i;
	char	*err_msg;

	i = digit_check(inputs[1]);
	if (i)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		err_msg = get_err_msg(inputs[1]);
		ft_putstr_fd(err_msg, STDERR_FILENO);
		free(err_msg);
		(*set)->last_exit_status = 255;
	}
	else if (inputs[2])
	{
		i = digit_check(inputs[1]);
		if (!i)
			ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		(*set)->last_exit_status = 1;
		(*set)->exit = 0;
		return ;
	}
	else
		(*set)->last_exit_status = (ft_atoi(inputs[1]) % 256);
}

int	ft_exit(char **inputs, t_setting **set)
{
	(*set)->exit = 1;
	if (!inputs)
	{
		(*set)->last_exit_status = 0;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		return (0);
	}
	else if (inputs[1])
		exit_with_input(inputs, set);
	else
	{
		(*set)->last_exit_status = 0;
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	}
	return (0);
}
