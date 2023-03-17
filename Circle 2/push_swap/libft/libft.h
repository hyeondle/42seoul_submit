/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:50:01 by hyeondle          #+#    #+#             */
/*   Updated: 2023/01/29 18:32:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
int		ft_isnumber(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
