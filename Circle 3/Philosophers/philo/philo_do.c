/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:49:24 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:23 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo **philo, t_times **time)
{
	unsigned long long	now;
	int					i;

	now = get_ms();
	i = (int)(now - (*time)->last_meal) + (*((*philo)->setting))->sleep;
	print_status(philo, "is sleeping");
	if (i >= (*((*philo)->setting))->die)
	{
		flow(((*((*philo)->setting))->die - \
				(int)(now - (*time)->last_meal)), \
					philo, time);
		alive_or_dead(philo, time);
	}
	else
	{
		flow((*((*philo)->setting))->sleep, philo, time);
		alive_or_dead(philo, time);
	}
	if ((*philo)->is_dead == 1 || dead_state(philo) == 1)
		return (1);
	return (0);
}

int	philo_get_fork(t_philo **philo)
{
	int	i;

	i = 0;
	if ((*philo)->id % 2 == 0)
	{
		while (fork_state((*philo)->right_fork) == 1)
			i = flow(1, philo, (*philo)->time);
		if (i)
			return (1);
		right_fork_first(philo, (*philo)->left_fork, \
			(*philo)->right_fork);
	}
	else
	{
		while (fork_state((*philo)->right_fork) == 1)
			i = flow(1, philo, (*philo)->time);
		if (i)
			return (1);
		left_fork_first(philo, (*philo)->left_fork, \
			(*philo)->right_fork);
	}
	return (0);
}

void	philo_eat(t_philo **philo, t_times **time)
{
	print_status(philo, "is eating");
	(*time)->last_meal = get_ms();
	if ((*((*philo)->setting))->limit != -1)
	{
		(*philo)->eat_count++;
		if ((*philo)->eat_count == (*((*philo)->setting))->limit)
			eat_limit_state(philo);
		if (eat_count_state(philo) == (*((*philo)->setting))->n_of_philo)
		{
			notice_philo_dead(philo);
			return ;
		}
	}
	flow((*((*philo)->setting))->eat, philo, time);
	put_down_fork((*philo)->left_fork, (*philo)->right_fork);
}
