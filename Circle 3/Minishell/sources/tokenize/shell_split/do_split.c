/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:43:43 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 10:54:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**do_split(char **tab, char *temp)
{
	size_t	i;
	size_t	k;
	char	**ttab;
	char	*ttemp;

	i = 0;
	k = 0;
	ttab = tab;
	ttemp = temp;
	while (ttemp[k] != 0)
	{
		while (ttemp[k] && ttemp[k] == ' ')
			k++;
		if (ttemp[k] != 0)
		{
			ttab[i] = put_word(ttemp, k);
			k = k + new_strlen_m(ttemp, k) - 1;
			i++;
		}
	}
	ttab[i] = NULL;
	return (ttab);
}
