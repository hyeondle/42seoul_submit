# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:18:24 by hyeondle          #+#    #+#              #
#    Updated: 2023/01/30 10:17:21 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isnumber.c ft_lstadd_back.c ft_lstadd_front.c\
		ft_lstnew.c ft_printf.c ft_split.c ft_strjoin.c put_char.c\
		put_decimal.c put_string.c put_unsigned_int.c put_void_pointer.c\
		utils.c

INCD	= ./

GCC		= gcc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

.c.o	:
			${GCC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCD}

$(NAME)	:	${OBJS}
			${LIB} $(NAME) ${OBJS}

all		:	$(NAME)

clean	:
			@${RM} ${OBJS}

fclean	:	clean
			${RM} $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
