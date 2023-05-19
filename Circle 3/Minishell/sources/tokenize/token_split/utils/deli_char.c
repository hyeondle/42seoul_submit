/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deli_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:55:38 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:55:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

char	*deli_char(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
