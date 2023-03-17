/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:01:39 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/15 11:17:00 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	notice_philo_dead(t_philo **philo)

{
	pthread_mutex_lock((*((*philo)->setting))->dead_state);
	(*((*philo)->setting))->someone_dead = 1;
	pthread_mutex_unlock((*((*philo)->setting))->dead_state);
}

int	dead_state_f_m(t_setting **set)
{
	int	i;

	pthread_mutex_lock((*set)->dead_state);
	i = (*set)->someone_dead;
	pthread_mutex_unlock((*set)->dead_state);
	return (i);
}

int	init_setting_mutex(t_setting **set)
{
	int	e;

	(*set)->write_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	(*set)->dead_state = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	(*set)->count_state = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	e = pthread_mutex_init((*set)->write_mutex, NULL);
	if (e != 0)
	{
		free_setting(set);
		return (-1);
	}
	e = pthread_mutex_init((*set)->dead_state, NULL);
	if (e != 0)
	{
		free_setting(set);
		return (-1);
	}
	e = pthread_mutex_init((*set)->count_state, NULL);
	if (e != 0)
	{
		free_setting(set);
		return (-1);
	}
	return (0);
}

void	control_fork_mutex_state(int flag, t_fork **fork)
{
	pthread_mutex_lock((*fork)->state);
	(*fork)->fork_state = flag;
	pthread_mutex_unlock((*fork)->state);
}

int	fork_state(t_fork **fork)
{
	int	i;

	pthread_mutex_lock((*fork)->state);
	i = (*fork)->fork_state;
	pthread_mutex_unlock((*fork)->state);
	return (i);
}
