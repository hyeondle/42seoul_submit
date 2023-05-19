/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:58:26 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 17:30:55 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*for_return;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	for_return = ft_lstnew(f(lst->content));
	if (!for_return)
		return (NULL);
	temp = for_return;
	lst = lst->next;
	while (!(lst == NULL))
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&for_return, del);
			return (NULL);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (for_return);
}
