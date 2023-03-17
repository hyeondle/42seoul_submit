/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:00:23 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/15 11:16:23 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	flow(int todo, t_philo **philo, t_times **time)
{
	unsigned long long	now;
	int					e;

	now = get_ms();
	while (todo >= (int)(get_ms() - now))
	{
		usleep(500);
		e = alive_or_dead(philo, time);
		if (e == 1)
			return (1);
	}
	return (0);
}

int	eat_count_state(t_philo **philo)
{
	int	i;

	pthread_mutex_lock((*((*philo)->setting))->count_state);
	i = (*((*philo)->setting))->eat_done;
	pthread_mutex_unlock((*((*philo)->setting))->count_state);
	return (i);
}

void	eat_limit_state(t_philo **philo)
{
	pthread_mutex_lock((*((*philo)->setting))->count_state);
	(*((*philo)->setting))->eat_done++;
	pthread_mutex_unlock((*((*philo)->setting))->count_state);
}

int	dead_state(t_philo **philo)
{
	int	i;

	pthread_mutex_lock((*((*philo)->setting))->dead_state);
	i = (*((*philo)->setting))->someone_dead;
	pthread_mutex_unlock((*((*philo)->setting))->dead_state);
	return (i);
}
