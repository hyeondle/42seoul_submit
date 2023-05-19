# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 15:17:23 by hyejeong          #+#    #+#              #
#    Updated: 2023/05/12 12:22:27 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER_DIR		=	./includes/
HEADER			=	minishell.h

SOURCE_DIR		=	./sources/

SOURCES			=	main.c\
					operation.c\
					frees.c\
					input/check_input_add.c\
					input/get_input.c\
					input/input_check.c\
					input/del_quotes.c\
					history/ft_add_history.c\
					history/init_history.c\
					history/save_history.c\
					execute/execute.c\
					execute/execute_utils.c\
					builtins/echo/ft_echo.c\
					builtins/env/ft_env.c\
					builtins/export/ft_export.c\
					builtins/export/ft_export_utils.c\
					builtins/exit/ft_exit.c\
					builtins/unset/ft_unset.c\
					builtins/pwd/ft_pwd.c\
					builtins/cd/ft_cd.c\
					environment/get_str.c\
					environment/add_env.c\
					environment/free_env.c\
					environment/get_env_key.c\
					environment/get_env_value.c\
					environment/init_env.c\
					environment/remove_env.c\
					environment/update_env.c\
					environment/remove_env_envp.c\
					environment/add_env_envp.c\
					environment/convert_env_to_str/convertion.c\
					tokenize/shell_split/do_split.c\
					tokenize/shell_split/put_word.c\
					tokenize/shell_split/shell_split.c\
					tokenize/shell_split/utils/check_quote.c\
					tokenize/shell_split/utils/new_strlen_m.c\
					tokenize/shell_split/utils/quote_leng.c\
					tokenize/shell_split/utils/tab_size.c\
					tokenize/token_split/split_by_case.c\
					tokenize/token_split/split_by_token.c\
					tokenize/token_split/sep_by_delims.c\
					tokenize/token_split/utils/check_delimeter_type_i.c\
					tokenize/token_split/utils/check_delimeter.c\
					tokenize/token_split/utils/deli_char.c\
					tokenize/token_split/utils/dtab_size.c\
					tokenize/token_split/utils/split_case_index_check.c\
					tokenize/token_split/utils/token_check.c\
					tokenize/token_split/utils/deli_char_over_delim.c\
					tokenize/token_split/utils/over_2_delims_i.c\
					tokenize/token_split/case/go_split.c\
					tokenize/token_split/case/token_split_case_no_back.c\
					tokenize/token_split/case/token_split_case_no_front.c\
					tokenize/token_split/case/go_split_over_delim.c\
					tokenize/token_split/case/token_split_case_no_back_over_delim.c\
					tokenize/token_split/case/token_split_case_no_front_over_delim.c\
					process/deque.c\
					process/exec.c\
					process/exec2.c\
					process/heredoc.c\
					process/heredoc2.c\
					process/node.c\
					process/redir.c\
					process/run.c\
					process/run2.c\
					process/run3.c\
					process/utils.c\
					process/signals.c\

SOURCE			=	$(addprefix $(SOURCE_DIR), $(SOURCES))
OBJECT			=	$(SOURCE:.c=.o)\

LIBFT_DIR		=	./libft/
LIBFT			=	$(LIBFT_DIR)libft.a
LIBFT_FLAG		=	-L$(LIBFT_DIR) -lft

READLINE_FLAG	=	-L/goinfre/hyejeong/.brew/opt/readline/lib -I/goinfre/hyejeong/.brew/opt/readline/include -lreadline

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
RM_OBJECT		=	rm -rf $(OBJECT)

.c.o			:
					$(CC) $(FLAGS) -I/goinfre/hyejeong/.brew/opt/readline/include -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

all				:	$(NAME)

$(LIBFT)		:
					make -C $(LIBFT_DIR)

$(NAME)			:	$(OBJECT) $(LIBFT) $(READLINE)
					$(CC) $(FLAGS) -I $(HEADER_DIR) $(OBJECT) $(READLINE_FLAG) $(LIBFT_FLAG) -o $(NAME)

clean			:
					$(RM_OBJECT)
					@make -C $(LIBFT_DIR) clean

fclean			:	clean
					rm -rf $(NAME)
					@make -C $(LIBFT_DIR) fclean

re				:
					@make fclean
					@make all

.PHONY			:	clean fclean re
