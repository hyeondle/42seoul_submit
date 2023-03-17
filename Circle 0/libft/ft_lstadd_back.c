/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:58:40 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:55:10 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tab;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tab = *lst;
	while (tab->next != NULL)
		tab = tab->next;
	tab->next = new;
}
