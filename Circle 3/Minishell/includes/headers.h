/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:41:06 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/29 10:43:25 by hyeondle         ###   ########.fr       */
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

#ifndef HEADERS_H
# define HEADERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/mylibft.h"

#endif