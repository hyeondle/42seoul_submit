# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:18:24 by hyeondle          #+#    #+#              #
#    Updated: 2022/08/25 13:56:46 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c put_char.c put_string.c put_unsigned_int.c put_void_pointer.c \
utils.c put_decimal.c

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
			${RM} ${OBJS}

fclean	:	clean
			${RM} $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
