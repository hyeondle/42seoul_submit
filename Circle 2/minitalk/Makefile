# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 14:39:30 by hyeondle          #+#    #+#              #
#    Updated: 2023/02/17 21:36:11 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server client

HEADERS_DIR	=	./
HEADERS		=	minitalk.h

SOURCES_DIR	=	./
SOURCES		=	server.c client.c
SOURCES_B	=	server_bonus.c client_bonus.c
SOURCE		=	$(addprefix $(SOURCES_DIR), $(SOURCES))
SOURCE_B	=	$(addprefix $(SOURCES_DIR), $(SOURCES_B))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_INCDS	=	$(LIBFT_DIR)

OBJECTS		=	${SOURCE:.c=.o}
OBJECTS_B	=	${SOURCE_B:.c=.o}

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -O3
LIBS		=	-L $(LIBFT_DIR) -lft
INCDS		=	-I $(HEADERS_DIR) -I $(LIBFT_DIR)

LIB_FLAG	=	ar rcs
RM			=	rm -f
RM_OBJECT	=	rm -rf $(OBJECTS) $(OBJECTS_B)

.DEFAULT_GOAL =	all

ifdef WITH_BONUS
	OBJECT = $(OBJECTS_B)
else
	OBJECT = $(OBJECTS)
endif

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(INCDS)

all : $(NAME)

$(NAME) : $(OBJECT) $(LIBFT)

ifneq ($(OBJECTS), $(OBJECT))
	$(CC) $(FLAGS) $(INCDS) server_bonus.o -o server $(LIBS)
	$(CC) $(FLAGS) $(INCDS) client_bonus.o -o client $(LIBS)
else
	$(CC) $(FLAGS) $(INCDS) server.o -o server $(LIBS)
	$(CC) $(FLAGS) $(INCDS) client.o -o client $(LIBS)
endif

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean :
	@make -C $(LIBFT_DIR) clean
	@$(RM_OBJECT)

fclean : clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re :
	@make fclean
	@make all

bonus		:
	make WITH_BONUS=1 all

.PHONY : clean fclean re bonus