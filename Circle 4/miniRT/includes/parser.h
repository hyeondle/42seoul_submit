/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:20:26 by hyejeong          #+#    #+#             */
/*   Updated: 2023/08/21 11:37:56 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "./ft_free.h"
# include "./errors.h"
# include "./sets.h"
# include "../libft/basic/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include "./set_object.h"

t_setting	*parser(int argc, char **argv);
void		parse(t_setting **set, char *line);
t_bool		check_param(char **info);
t_bool		check_param2(char **info);
t_bool		check_param_cy(char **info);
t_bool		check_param_pl(char **info);
t_bool		check_param_sp(char **info);
t_bool		check_param_rgb(char *str);
t_bool		check_param_double(char *str, double min, double max);
t_bool		check_param_a(char **info);
t_bool		check_param_c(char **info);
t_bool		check_param_l(char **info);
int			size_2arr(char **arr);
t_bool		check_param_int(char *str, int min, int max);
t_bool		free_false(char **arr);
void		free_p_exit(char **arr);
void		check_extension(int argc, char **argv);

#endif