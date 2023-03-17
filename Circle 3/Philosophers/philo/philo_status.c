/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:48:24 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/17 14:19:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_exit(t_philo **philo)
{
	pthread_mutex_lock((*((*philo)->setting))->write_mutex);
	(*((*philo)->setting))->write_status = 1;
	put_down_fork((*philo)->left_fork, (*philo)->right_fork);
	pthread_mutex_unlock((*((*philo)->setting))->write_mutex);
}

void	*operation(void *philo_i)
{
	t_philo	*philo;
	int		e;

	philo = (t_philo *)philo_i;
	if ((*(philo->setting))->n_of_philo == 1)
		flow((*(philo->setting))->die, &philo, philo->time);
	if (philo->id % 2 == 1)
		usleep(500);
	while (philo->is_dead == 0)
	{
		alive_or_dead(&philo, philo->time);
		if (philo->is_dead == 1 || dead_state(&philo) == 1)
			break ;
		e = philo_get_fork(&philo);
		if (e == 1 || philo->is_dead == 1 || dead_state(&philo) == 1)
			break ;
		philo_eat(&philo, philo->time);
		e = philo_sleep(&philo, philo->time);
		if (e == 1 || philo->is_dead == 1 || dead_state(&philo) == 1)
			break ;
		print_status(&philo, "is thinking");
	}
	philo_exit(&philo);
	return (0);
}

void	fight_philos(t_philo **philo, t_setting **set)
{
	int			i;

	i = 0;
	while (i < (*set)->n_of_philo)
	{
		pthread_join(philo[i]->thread_id, NULL);
		i++;
	}
}

int	alive_or_dead(t_philo **philo, t_times **time)
{
	unsigned long long	now;
	int					starve;

	now = get_ms();
	starve = (int)(now - (*time)->last_meal);
	if (starve >= (*((*philo)->setting))->die)
	{
		if (dead_state(philo) == 1)
			return (1);
		print_status(philo, "died");
		pthread_mutex_lock((*((*philo)->setting))->write_mutex);
		(*((*philo)->setting))->write_status = 1;
		notice_philo_dead(philo);
		(*philo)->is_dead = 1;
		pthread_mutex_unlock((*((*philo)->left_fork))->fork);
		pthread_mutex_unlock((*((*philo)->right_fork))->fork);
		pthread_mutex_unlock((*((*philo)->setting))->write_mutex);
		return (1);
	}
	return (0);
}

void	init_philo_status(t_philo **philo, t_fork **forks, \
					t_times **time, t_setting **set)
{
	int	i;
	int	n;

	n = (*set)->n_of_philo;
	i = 0;
	while (i <= n - 1)
	{
		philo[i]->id = i + 1;
		philo[i]->setting = set;
		philo[i]->time = &time[i];
		philo[i]->left_fork = &forks[i];
		if (i != 0)
			philo[i]->right_fork = &forks[i - 1];
		else
			philo[i]->right_fork = &forks[n - 1];
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_create(&(philo[i]->thread_id), NULL, operation, philo[i]);
		i++;
	}
}
