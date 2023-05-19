/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:05:42 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:35:34 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/minishell.h"

void	check_perm_dir(char **cmd_args)
{
	struct stat	sb;

	if (cmd_args[0][0] == '.' || cmd_args[0][0] == '/')
	{
		if (stat(cmd_args[0], &sb) != -1)
		{
			if ((sb.st_mode & S_IFMT) == S_IFDIR)
				putstr_exit(" is a directory\n", 2, 126);
			else if (!(sb.st_mode & S_IXUSR))
				putstr_exit(" Permission denied\n", 2, 126);
		}
	}
}

void	errors(char c)
{
	if (c == '.' || c == '/')
		putstr_exit(" No such file or directory\n", 2, 127);
	else
		putstr_exit(" command not found\n", 2, 127);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	token_env_path = tokenize(envp);
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");
		temp = buffer;
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		if (access(buffer, F_OK | X_OK) == 0)
			return (free_and_return(token_env_path, buffer));
		else
			free(buffer);
		j++;
	}
	errors(cmd[0]);
	return (NULL);
}

t_bool	exec(char **cmd_args, char **envp, t_setting **set)
{
	char		*cmd_with_path;

	if (!cmd_args[0])
		return (FALSE);
	if (ft_strcmp("echo", cmd_args[0]) != 0 && \
	ft_strcmp("env", cmd_args[0]) != 0 && ft_strcmp("export", cmd_args[0]) != 0)
	{
		check_perm_dir(cmd_args);
		cmd_with_path = find_command_path(cmd_args[0], envp);
		if (execve(cmd_with_path, cmd_args, envp) == -1)
			putstr_exit("error\n", 2, 127);
	}
	else
	{
		if (ft_strcmp("export", cmd_args[0]) == 0)
		{
			ft_export(set, cmd_args);
			exit(0);
		}
		go_execute(cmd_args, set, cmd_args[0]);
	}
	return (TRUE);
}
