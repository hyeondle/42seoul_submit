/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:37:23 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:17 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_time(t_times **time, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		memset(time[n], 0, sizeof(t_times));
		free(time[n]);
		n++;
	}
	free(time);
}

void	free_forks(t_fork **forks, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		pthread_mutex_destroy(forks[k]->fork);
		free(forks[k]);
		k++;
	}
	free(forks);
}

void	free_philo(t_philo **philo, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		memset(philo[k], 0, sizeof(t_philo));
		free(philo[k]);
		k++;
	}
	free(philo);
}

void	free_setting(t_setting **set)
{
	pthread_mutex_destroy((*set)->count_state);
	pthread_mutex_destroy((*set)->dead_state);
	pthread_mutex_destroy((*set)->write_mutex);
	memset((*set), 0, sizeof(t_setting));
	free((*set)->write_mutex);
	free(*set);
}

void	free_all(t_times **time, t_setting *setting, \
				t_philo **philo, t_fork **forks)
{
	int	i;

	i = setting->n_of_philo;
	free_time(time, i);
	free_forks(forks, i);
	free_setting(&setting);
	free_philo(philo, i);
}
