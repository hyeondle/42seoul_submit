/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:24:55 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/06 00:30:35 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/wait.h>

typedef enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef struct s_history
{
	char				*history;
	struct s_history	*next;
}						t_history;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_env_list
{
	t_env				env;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_setting
{
	int				exit;
	int				last_exit_status;
	char			**envp;
	t_env_list		*env_list;
	t_history		*s_history;
	t_history		*l_history;
}				t_setting;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef enum e_rw
{
	READ = 0,
	WRITE = 1
}			t_rw;

typedef struct s_info
{
	int					num_pipe;
	int					**pipes;
	pid_t				*arr_pid;
	char				**envp;
}				t_info;

typedef struct s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

typedef struct s_node
{
	int				idx;
	int				num_heredoc;
	char			**cmd;
	char			**order_redir;
	char			**file_redir;
	char			**filename_heredoc;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_heredoc
{
	char	**terminators;
	char	**filename_temp;
	int		size_heredoc;
	int		*fd_heredoc;
}				t_heredoc;

#endif