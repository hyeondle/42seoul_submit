/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:41:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 23:27:08 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	quote_change(t_quote *quote, char c)
{
	if (c == '\'' || c == '\"')
	{
		if (c == '\'' && *quote == SINGLE)
		{
			*quote = NONE;
			return (1);
		}
		else if (c == '\'' && *quote == NONE)
		{
			*quote = SINGLE;
			return (1);
		}
		else if (c == '\"' && *quote == DOUBLE)
		{
			*quote = NONE;
			return (1);
		}
		else if (c == '\"' && *quote == NONE)
		{
			*quote = DOUBLE;
			return (1);
		}
	}
	return (0);
}

static int	quote_check(char *str)
{
	t_quote	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quote = NONE;
	while (str[i])
	{
		if (quote_change(&quote, str[i]))
			j++;
		i++;
	}
	return (j);
}

static char	*deleted_str(char *str, char *temp, t_quote quote)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (quote_change(&quote, str[i]))
		{
			i++;
			continue ;
		}
		else
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*del_quotes(char *str)
{
	char	*temp;
	int		i;
	int		j;
	t_quote	quote;

	j = 0;
	i = quote_check(str);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	quote = NONE;
	return (deleted_str(str, temp, quote));
}
