# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 13:40:55 by hyeondle          #+#    #+#              #
#    Updated: 2023/01/30 11:12:56 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

HEADERS_DIR	= ./includes/
HEADERS		=	push_swap.h


SOURCES_DIR	= ./sources/
SOURCES		= 	main.c\
				init.c\
				orders.c\
				do_orders_1.c do_orders_2.c do_orders_3.c\
				errorchecker.c\
				sort.c\
				sort_main.c sort_main_utils.c\
				sort_specific.c sort_specific2.c\
				utils.c utils2.c utils3.c
SOURCE		=	$(addprefix $(SOURCES_DIR), $(SOURCES))

LIBFT_DIR	= ./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_INCDS	=	$(LIBFT_DIR)

OBJECTS		=	${SOURCE:.c=.o}

CC			= cc
FLAGS		= -Wall -Werror -Wextra -O3
LIBS		= -L $(LIBFT_DIR) -lft
INCDS		= -I $(HEADERS_DIR) -I $(LIBFT_DIR)

LIB_FLAG	= ar rcs
RM			= rm -f
RM_OBJECT	= rm -rf $(OBJECTS)

.DEFAULT_GOAL = all

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(INCDS)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(FLAGS) $(INCDS) $(OBJECTS) -o $(NAME) $(LIBS)

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

.PHONY : clean fclean re