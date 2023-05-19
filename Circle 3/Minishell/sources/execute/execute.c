/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:43:19 by Linsio            #+#    #+#             */
/*   Updated: 2023/05/06 23:30:26 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	execute(char **inputs, t_setting **set)
{
	char	*o;
	int		flag;

	flag = 0;
	o = inputs[0];
	if (o == NULL)
		return (1);
	if (execute_check(o) != 0)
		go_execute(inputs, set, o);
	else
		run_cmd(inputs, (*set)->envp, set);
	init_signalaction();
	return ((*set)->last_exit_status);
}
