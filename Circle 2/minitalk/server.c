/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:20:55 by hyeondle          #+#    #+#             */
/*   Updated: 2023/02/17 21:24:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	handler(int sig, siginfo_t *info, void *oldsiga)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_putchar_fd(c, 1);
		bit_count = 0;
	}
	(void)oldsiga;
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
