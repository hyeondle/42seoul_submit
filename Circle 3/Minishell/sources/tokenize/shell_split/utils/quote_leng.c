/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_leng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:45:30 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:46:17 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

size_t	quote_leng(const char *s, size_t k)
{
	size_t	k_p;

	k_p = k + 1;
	if (s[k] == '\'')
	{
		while (s[k_p] != '\'' && s[k_p] != '\0')
			k_p++;
	}
	else if (s[k] == '\"')
	{
		while (s[k_p] != '\"' && s[k_p] != '\0')
			k_p++;
	}
	else
		return (0);
	return (k_p);
}
