/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:48:05 by Linsio            #+#    #+#             */
/*   Updated: 2023/05/05 22:41:06 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_cd(char **inputs, t_setting **set)
{
	char	*err_str;

	if (chdir(inputs[1]) != 0)
	{
		(*set)->last_exit_status = 1;
		err_str = ft_strjoin("cd: ", inputs[1]);
		perror(err_str);
		free(err_str);
		return (1);
	}
	return (0);
}
