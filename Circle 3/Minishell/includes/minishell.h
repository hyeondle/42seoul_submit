/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/12 13:16:54 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
readline.h	=	readline
history.h	=	re_clear_history, rl_on_new_line,
				rl_replace_line, re_redisplay, add_history
stdio.h		=	printf, strerror, perror
stdlib.h	=	malloc, free
sys/stat.h	=	getcwd, chdir, stat, lstat, fstat, unlink, execve
dirent.h	=	opendir, readdir, closedir
unistd.h	=	write, access, dup, dup2, pipe
signal.h	=	fork, wait, waitpid, wait3, wiat4, signal,
				sigaction, sigemptyset, sigaddset, kill, exit
sys/ioctl.h	=	isatty, ttyname, ttyslot, ioctl
stdlib.h	=	getenv
termios.h	=	tcsetattr, tcgetattr
termcap		=	tgetnet, tgetflag, tgetnum, tgetstr, tgoto, tputs
fcntl.h		=	open, read, close
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./headers.h"
# include "./pipex.h"
# include "./structs.h"

# define HISTORY_FILE	".minishell_history"
# ifndef HISTORY_SIZE
#  define HISTORY_SIZE	1024
# endif

/*			main				*/
void	init_signalaction(void);
void	free_settings(t_setting *set);

/*			actors				*/
void	make_void(int argc, char **argv);
void	operation(char *input, t_setting **set);

/*			history				*/
void	init_history(t_setting **setting);
void	ft_add_history(char *input, t_setting **set);
void	save_history(t_setting **setting);

/*			environment			*/
void	init_env(char **envp, t_setting **set);
int		add_env_envp(t_setting **set, const char *str);
int		add_env(t_env_list **env, const char *key_value_pair, t_setting **set);
int		remove_env_envp(t_setting **set, const char *key);
int		remove_env(t_env_list **env, const char *key, t_setting **set);
char	*get_env_value(t_env_list *env, const char *key, t_setting **set);
char	*get_env_key(char *str, int i);
int		update_env(t_env_list *env, const char *key, const char *new_value);
void	free_env(t_env_list	*env);
char	*convertion(t_setting **set, char *str);
char	*get_key(const char *str);
char	*get_value(const char *str);

/*			input				*/
char	*get_input(t_setting **set);
int		input_check(char *input);
char	*check_input_add(char *additional);
char	*del_quotes(char *str);

/*			execute				*/
int		execute(char **inputs, t_setting **set);
int		execute_check(char *o);
int		go_execute(char **inputs, t_setting **set, char *o);

/*			tokenize			*/
//			shell split			//
char	**shell_split(char const *s);
char	*put_word(char *str, size_t s);
char	**do_split(char **tab, char *temp);
//			shell split utils	//
size_t	quote_leng(const char *s, size_t k);
size_t	tab_size(char *s);
t_quote	check_quote(char temp);
size_t	new_strlen_m(char *str, size_t k);

//			token split			//
char	**split_by_token(char **str);
char	**split_by_case(char **str, int i, int k);
char	**over_2_delims(char **str, int i, int k);
//			case				//
char	**go_split(char **str, int i, int k);
char	**token_split_case_no_back(char **str, int i, int k);
char	**token_split_case_no_front(char **str, int i, int k);
char	**go_split_over_delim(char **str, int i, int k, int j);
char	**token_split_case_no_back_over_delim(char **str, int i, int k, int j);
char	**token_split_case_no_front_over_delim(char **str, int i, int k, int j);
//			token split utils	//
int		split_case_index_check(char **str, int i, int k);
int		token_check(char c);
int		check_delimeter(char *str);
int		check_delimeter_type_i(char	*str);
size_t	dtab_size(char **str);
char	*deli_char(char c);
char	*deli_char_over_delim(char c, int i, int j);
int		over_2_delims_i(int k);

/*			builtins			*/
int		ft_echo(char **inputs, t_setting **set);
int		ft_env(char **envp, t_setting **set);
int		ft_exit(char **inputs, t_setting **set);
int		ft_export(t_setting **set, char **inputs);
void	free_temp_env(char **temp_env);
int		ft_unset(t_setting **set, char **inputs);
int		ft_pwd(void);
int		ft_cd(char **inputs, t_setting **set);
//			export utils		//
char	*make_export_str(char *str);
void	go_run_cmd(char **inputs, t_setting **set, int i);
void	report_error(const char *c, t_setting **set);
int		check_export_input(char *str);
int		check_pipe(char **str);

#endif