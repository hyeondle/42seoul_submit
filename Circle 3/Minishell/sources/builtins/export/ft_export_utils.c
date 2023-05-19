/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:01 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/06 13:12:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*make_export_str(char *str)
{
	char	*key;
	char	*value;
	char	*equal;
	char	*rstr;

	equal = ft_strchr(str, '=');
	key = ft_strndup(str, equal - str);
	value = ft_strdup(equal + 1);
	rstr = ft_strjoin("declare -x ", key);
	free(key);
	key = ft_strjoin(rstr, "=\"");
	free(rstr);
	rstr = ft_strjoin(key, value);
	free(value);
	value = ft_strjoin(rstr, "\"");
	free(rstr);
	free(key);
	rstr = ft_strjoin(value, "\n");
	free(value);
	return (rstr);
}

void	go_run_cmd(char **inputs, t_setting **set, int i)
{
	char	**r_input;
	int		j;
	int		k;

	j = 0;
	while (inputs[j])
		j++;
	r_input = (char **)malloc(sizeof(char *) * (j - i + 1));
	k = i + 1;
	j = 0;
	while (inputs[k])
	{
		r_input[j] = ft_strdup(inputs[k]);
		k++;
		j++;
	}
	r_input[j] = NULL;
	run_cmd(r_input, (*set)->envp, set);
	free_temp_env(r_input);
}

void	report_error(const char *c, t_setting **set)
{
	char	*err_str;
	char	*err_str2;

	err_str = ft_strjoin("export: `", c);
	err_str2 = ft_strjoin(err_str, "\': not a valid identifier\n");
	ft_putstr_fd(err_str2, STDERR_FILENO);
	free(err_str);
	free(err_str2);
	(*set)->last_exit_status = 1;
}

int	check_export_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if (i == 0 || !str[i - 1] || !(ft_isalpha(str[0]) || str[0] == '_'))
				return (1);
			return (0);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (1);
		i++;
	}
	if (!ft_isalpha(str[0]))
		return (1);
	return (0);
}

int	check_pipe(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp("|", str[i]) == 0 || ft_strcmp("<", str[i]) == 0 || \
		ft_strcmp(">", str[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
