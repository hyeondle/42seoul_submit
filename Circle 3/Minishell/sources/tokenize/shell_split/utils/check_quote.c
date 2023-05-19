/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:47:11 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:48:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_quote	check_quote(char temp)
{
	if (temp == '\'')
		return (SINGLE);
	else if (temp == '\"')
		return (DOUBLE);
	else
		return (NONE);
}
