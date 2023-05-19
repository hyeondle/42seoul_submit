/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:42:22 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 10:54:07 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*put_word(char *str, size_t s)
{
	size_t	i;
	size_t	size;
	char	*word;

	i = 0;
	size = new_strlen_m(str, s);
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = str[s + i];
		i++;
	}
	if (word[i - 1] == ' ')
		word[i - 1] = '\0';
	word[i] = '\0';
	return (word);
}
