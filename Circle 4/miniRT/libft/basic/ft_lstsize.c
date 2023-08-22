/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:58:31 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:55:18 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (!lst)
		return (0);
	temp = lst;
	while ((temp->next) != 0)
	{
		temp = temp->next;
		count++;
	}
	if (temp->next == NULL)
		count++;
	return (count);
}
