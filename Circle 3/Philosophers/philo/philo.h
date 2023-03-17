/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:44:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/03/15 11:16:24 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>	 	 	// usleep, write
// #include <stdio.h>       	// printf
// #include <string.h>			// memset
// #include <stdlib.h>   	   // malloc, free
// #include <sys/time.h>   	   // gettimeofday
// #include <pthread.h>    	   // pthread_create, pthread_detach, pthread_join, 
//								pthread_mutex_init, pthread_mutex_destroy, 
//								pthread_mutex_lock, pthread_mutex_unlock
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/*			structs			*/
typedef struct s_fork
{
	int				fork_state;
	pthread_mutex_t	*state;
	pthread_mutex_t	*fork;
}					t_fork;

typedef struct s_times
{
	unsigned long long	main_time;
	unsigned long long	last_meal;
}						t_times;

typedef struct s_setting
{
	int				n_of_philo;
	int				die;
	int				eat;
	int				sleep;
	int				limit;
	int				eat_done;
	pthread_mutex_t	*count_state;
	int				someone_dead;
	int				dead_philo_id;
	pthread_mutex_t	*dead_state;
	int				write_status;
	pthread_mutex_t	*write_mutex;
}					t_setting;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				eat_count;
	t_setting		**setting;
	t_times			**time;
	pthread_t		thread_id;
	t_fork			**left_fork;
	t_fork			**right_fork;
	int				left;
	int				right;
}					t_philo;

/*			mutex_checker		*/
int					flow(int todo, t_philo **philo, t_times **time);
void				eat_limit_state(t_philo **philo);
int					eat_count_state(t_philo **philo);
int					dead_state(t_philo **philo);
int					dead_state_f_m(t_setting **set);
void				notice_philo_dead(t_philo **philo);
int					init_setting_mutex(t_setting **set);
void				control_fork_mutex_state(int flag, t_fork **fork);
int					fork_state(t_fork **fork);
/*			philo_do			*/
int					philo_get_fork(t_philo **philo);
void				philo_eat(t_philo **philo, t_times **time);
int					philo_sleep(t_philo **philo, t_times **time);

/*			philo_fork			*/
void				put_down_fork(t_fork **left_fork, t_fork **right_fork);
void				left_fork_first(t_philo **philo, t_fork **left_fork, \
									t_fork **right_fork);
void				right_fork_first(t_philo **philo, t_fork **left_fork, \
									t_fork **right_fork);

/*			philo_status		*/
int					alive_or_dead(t_philo **philo, t_times **time);
void				*operation(void *philo_i);
void				fight_philos(t_philo **philo, t_setting **set);
void				init_philo_status(t_philo **philo, t_fork **forks, \
									t_times **time, t_setting **set);

/*			init			*/
t_setting			*init_philo_setting(int argc, char **argv);
t_times				**init_time(int n_of_philo);
t_philo				**init_philo_philos(int n_of_philo);
int					init_each_fork(t_fork **fork);
t_fork				**init_philo_forks(int n);

/*			handler			*/
void				printerror(int e_type);
int					input_check(int argc, char **argv);
int					decimal_checker(char *str);
/*			free			*/
void				free_time(t_times **time, int i);
void				free_philo(t_philo **philo, int i);
void				free_forks(t_fork **forks, int i);
void				free_setting(t_setting **set);
void				free_all(t_times **time, t_setting *setting, \
							t_philo **philo, t_fork **forks);

/*			utils			*/
int					ft_atoi(const char *str);
unsigned long long	get_ms(void);
void				print_status(t_philo **philo, char *status);

#endif
