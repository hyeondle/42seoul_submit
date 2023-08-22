/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:57:00 by hyeondle          #+#    #+#             */
/*   Updated: 2023/08/06 18:29:01 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/object.h"
#include <stdlib.h>

t_object	*object(t_object_type type, void *element, t_vector albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

void	oadd(t_object **list, t_object *newo)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = newo;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = newo;
}

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
