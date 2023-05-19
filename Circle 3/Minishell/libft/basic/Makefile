# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:18:24 by hyeondle          #+#    #+#              #
#    Updated: 2023/04/29 05:09:53 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftbasic.a

SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_itoa.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memset.c\
			ft_memmove.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strcmp.c\
			ft_strndup.c\
			ft_strncmp.c\
			ft_strnlen.c\
			ft_swap.c\

OBJS	= ${SRCS:.c=.o}
INCD	= ./

GCC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs

RM		= rm -f

.c.o	:
			${GCC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCD}

$(NAME)	:	$(OBJS)
			${LIB} $(NAME) ${OBJS}

all		:	$(NAME)

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} $(NAME)

re		:	fclean all

.PHONY	:	all bonus clean fclean re
