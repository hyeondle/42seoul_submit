/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:31:56 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/13 16:17:38 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	free_info(char **info)
{
	int	i;

	i = 0;
	while (info[i] != NULL)
	{
		free(info[i]);
		i++;
	}
	free(info);
}

void	free_obj(t_object *obj)
{
	t_object	*temp;

	while (obj != NULL)
	{
		free(obj->element);
		temp = obj->next;
		free(obj);
		obj = temp;
	}
}

void	free_set(t_setting *set)
{
	t_setting	*temp;

	while (set != NULL)
	{
		free(set->object);
		free(set->type);
		temp = set->next;
		free(set);
		set = temp;
	}
}
