/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 02:20:30 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:25 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_space_count(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			is_negative;
	int			space_count;
	long long	ft_result;
	int			i;

	ft_result = 0;
	is_negative = 1;
	space_count = ft_space_count((char *)str);
	i = space_count;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_result = ft_result * 10 + str[i] - '0';
		i++;
		if (ft_result * is_negative > 2147483647)
			return (-1);
		else if (ft_result * is_negative < -2147483648)
			return (-2);
	}
	return ((int)ft_result * is_negative);
}

unsigned long long	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philo **philo, char *status)
{
	unsigned long long	t;
	t_setting			*set;
	t_times				**time;

	set = *((*philo)->setting);
	time = (*philo)->time;
	pthread_mutex_lock(set->write_mutex);
	t = get_ms() - (*time)->main_time;
	if ((*philo)->is_dead || dead_state(philo))
	{
		pthread_mutex_unlock(set->write_mutex);
		return ;
	}
	printf("%llu %d %s\n", t, (*philo)->id, status);
	pthread_mutex_unlock(set->write_mutex);
}
