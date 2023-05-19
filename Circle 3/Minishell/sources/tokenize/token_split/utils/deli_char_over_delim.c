/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deli_char_over_delim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:42:03 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 08:54:33 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	*deli_char_over_delim(char c, int i, int j)
{
	char	*str;
	int		k;

	k = 0;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		str[k] = c;
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
