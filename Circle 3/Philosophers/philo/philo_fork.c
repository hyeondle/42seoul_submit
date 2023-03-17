/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:50:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:24 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_fork(t_fork **left_fork, t_fork **right_fork)
{
	control_fork_mutex_state(0, left_fork);
	pthread_mutex_unlock((*left_fork)->fork);
	control_fork_mutex_state(0, right_fork);
	pthread_mutex_unlock((*right_fork)->fork);
}

void	right_fork_first(t_philo **philo, t_fork **left_fork, \
					t_fork **right_fork)
{
	control_fork_mutex_state(1, right_fork);
	pthread_mutex_lock((*right_fork)->fork);
	print_status(philo, "has taken a fork");
	control_fork_mutex_state(1, left_fork);
	pthread_mutex_lock((*left_fork)->fork);
	print_status(philo, "has taken a fork");
}

void	left_fork_first(t_philo **philo, t_fork **left_fork, \
					t_fork **right_fork)
{
	control_fork_mutex_state(1, left_fork);
	pthread_mutex_lock((*left_fork)->fork);
	print_status(philo, "has taken a fork");
	control_fork_mutex_state(1, right_fork);
	pthread_mutex_lock((*right_fork)->fork);
	print_status(philo, "has taken a fork");
}
