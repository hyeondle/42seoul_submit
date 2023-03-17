/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:01:14 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:18 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_setting	*init_philo_setting(int argc, char **argv)
{
	t_setting	*setting;
	int			e;

	setting = (t_setting *)malloc(sizeof(t_setting));
	if (!setting)
	{
		printerror(3);
		return (0);
	}
	memset(setting, 0, sizeof(t_setting));
	setting->n_of_philo = ft_atoi(argv[1]);
	setting->die = ft_atoi(argv[2]);
	setting->eat = ft_atoi(argv[3]);
	setting->sleep = ft_atoi(argv[4]);
	setting->limit = -1;
	setting->eat_done = 0;
	setting->someone_dead = 0;
	if (argc == 6)
		setting->limit = ft_atoi(argv[5]);
	e = init_setting_mutex(&setting);
	if (e != 0)
		return (0);
	return (setting);
}

t_times	**init_time(int n_of_philo)
{
	t_times				**time;
	unsigned long long	main_time;
	int					i;

	time = (t_times **)malloc(sizeof(t_times *) * n_of_philo);
	if (!time)
		return (0);
	i = 0;
	main_time = get_ms();
	while (i < n_of_philo)
	{
		time[i] = (t_times *)malloc(sizeof(t_times));
		if (!time[i])
		{
			free_time(time, i);
			return (0);
		}
		time[i]->main_time = main_time;
		time[i]->last_meal = main_time;
		i++;
	}
	return (time);
}

t_philo	**init_philo_philos(int n_of_philo)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)malloc(sizeof(t_philo *) * n_of_philo);
	if (!philo)
	{
		printerror(3);
		return (0);
	}
	i = 0;
	while (i < n_of_philo)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philo[i])
		{
			free_philo(philo, i);
			return (0);
		}
		memset(philo[i], 0, sizeof(t_philo));
		i++;
	}
	return (philo);
}

int	init_each_fork(t_fork **fork)
{
	pthread_mutex_t	*da_fork;
	pthread_mutex_t	*state;
	int				e;

	da_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	state = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	e = pthread_mutex_init(da_fork, NULL);
	if (!da_fork || e != 0)
		return (-1);
	e = pthread_mutex_init(state, NULL);
	(*fork)->fork = da_fork;
	(*fork)->fork_state = 0;
	(*fork)->state = state;
	return (0);
}

t_fork	**init_philo_forks(int n)
{
	t_fork	**forks;
	int		i;
	int		e;

	forks = (t_fork **)malloc(sizeof(t_fork *) * n);
	if (!forks)
	{
		printerror(3);
		return (0);
	}
	i = 0;
	while (i < n)
	{
		forks[i] = (t_fork *)malloc(sizeof(t_fork));
		e = init_each_fork(&forks[i]);
		if (!forks[i] || e != 0)
		{
			free_forks(forks, i);
			return (0);
		}
		i++;
	}
	return (forks);
}
