/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:58:34 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:55:17 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*truc;
	int		i;
	int		j;

	if (!lst)
		return (0);
	i = 0;
	j = 0;
	truc = lst;
	while (truc->next != 0)
	{
		i++;
		truc = truc->next;
	}
	truc = lst;
	while (j < i)
	{
		truc = truc->next;
		j++;
	}
	return (truc);
}
