# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:18:24 by hyeondle          #+#    #+#              #
#    Updated: 2022/07/15 18:12:29 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_strdup.c ft_calloc.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putstr_fd.c

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c

INCD	= ./

GCC		= gcc
CFLAG	= -Wall -Wextra -Werror
LIB		= ar rcs

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

RM		= rm -f

ifdef WITH_BONUS
	OBJ_USE = ${OBJS} ${OBJS_B}
else
	OBJ_USE = ${OBJS}
endif

.c.o	:
			${GCC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCD}

$(NAME)	:	${OBJ_USE}
			${LIB} $(NAME) ${OBJ_USE}

all		:	$(NAME)

bonus	:	
			make WITH_BONUS=1 all

clean	:
			${RM} ${OBJS} ${OBJS_B}

fclean	:	clean
			${RM} $(NAME)

re		:	fclean all

.PHONY	:	all bonus clean fclean re
