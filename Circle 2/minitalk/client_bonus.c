/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:20:53 by hyeondle          #+#    #+#             */
/*   Updated: 2023/02/17 21:32:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	send_bit(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_bit(server_pid, message[i]);
		i++;
	}
	send_bit(server_pid, message[i]);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server-pid] [message]\n", 2);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}
