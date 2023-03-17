/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:50:01 by hyeondle          #+#    #+#             */
/*   Updated: 2022/10/21 15:08:48 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char *s, int start, int len);

// libft
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *str);
char	*ft_strdup2(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
void	ft_deltable(char **tab);

#endif
