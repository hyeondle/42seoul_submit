/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:44:25 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:44:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**shell_split(char const *s)
{
	char	**tab;
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	tab = (char **)malloc(sizeof(char *) * (tab_size(temp) + 1));
	if (!tab)
		return (NULL);
	tab = do_split(tab, temp);
	return (tab);
}
