/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:39:09 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:41:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init_map.h"

int	size_list(t_setting *set)
{
	int			i;
	t_setting	*node;

	i = 0;
	node = set;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_vector	compute_dynamic_vup(t_vector orientation)
{
	if (fabs(orientation.x) > fabs(orientation.y) && \
		fabs(orientation.x) > fabs(orientation.z))
		return (vector(0, 1, 0));
	else if (fabs(orientation.y) > fabs(orientation.x) && \
		fabs(orientation.y) > fabs(orientation.z))
		return (vector(1, 0, 0));
	else
		return (vector(0, 1, 0));
}
