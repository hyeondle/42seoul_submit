/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:32:05 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/06 18:16:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include <stdlib.h>
# include "./object.h"
# include "./sets.h"

void	free_tab(char **tab);
void	free_info(char **info);
void	free_obj(t_object *obj);
void	free_set(t_setting *set);

#endif