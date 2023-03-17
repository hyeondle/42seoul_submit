# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:36:14 by hyeondle          #+#    #+#              #
#    Updated: 2022/10/21 14:14:32 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_bzero.c ft_calloc.c ft_memset.c\
ft_split.c ft_strdup.c get_next_line.c get_next_line_utils.c\
ft_deltable.c

INCD	= ./

GCC		= cc
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

.PHONY	:	all bonus clean fclean re