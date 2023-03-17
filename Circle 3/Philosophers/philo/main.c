/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:53:51 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/17 21:21:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_times			**time;
	t_setting		*setting;
	t_philo			**philo;
	t_fork			**forks;

	if (input_check(argc, argv) != 1)
		return (0);
	setting = init_philo_setting(argc, argv);
	time = init_time(setting->n_of_philo);
	philo = init_philo_philos(setting->n_of_philo);
	forks = init_philo_forks(setting->n_of_philo);
	init_philo_status(philo, forks, time, &setting);
	fight_philos(philo, &setting);
	free_all(time, setting, philo, forks);
	return (0);
}
