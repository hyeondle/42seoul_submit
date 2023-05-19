/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/12 13:17:13 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

static void	handler(int sig, siginfo_t *info, void *oldsiga)
{
	(void)info;
	(void)oldsiga;
	if (sig == SIGQUIT)
		rl_redisplay();
	else if (sig == SIGINT)
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		printf("\n");
		rl_redisplay();
	}
}

void	init_signalaction(void)
{
	struct sigaction	act;

	rl_catch_signals = 0;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

static t_setting	*init_set(char **envp)
{
	t_setting	*set;

	set = (t_setting *)malloc(sizeof(t_setting));
	if (!set)
		exit(1);
	set->last_exit_status = 0;
	set->l_history = NULL;
	set->s_history = NULL;
	init_env(envp, &set);
	init_history(&set);
	init_signalaction();
	return (set);
}

static int	unclosed_quote(char *input)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (input[i])
	{
		if (quote == NONE && input[i] == '\'')
			quote = SINGLE;
		else if (quote == NONE && input[i] == '\"')
			quote = DOUBLE;
		else if (quote == DOUBLE && input[i] == '\"')
			quote = NONE;
		else if (quote == SINGLE && input[i] == '\'')
			quote = NONE;
		i++;
	}
	if (quote != NONE)
	{
		free(input);
		input = NULL;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_setting	*set;
	char		*input;
	int			i;

	make_void(argc, argv);
	signal(SIGINT, SIG_IGN);
	set = init_set(envp);
	while (1)
	{
		input = get_input(&set);
		if (!input)
			break ;
		if (unclosed_quote(input))
			continue ;
		ft_add_history(input, &set);
		operation(input, &set);
		free(input);
		if (set->exit == 1)
			break ;
	}
	save_history(&set);
	i = set->last_exit_status;
	free_settings(set);
	rl_clear_history();
	return (i);
}
