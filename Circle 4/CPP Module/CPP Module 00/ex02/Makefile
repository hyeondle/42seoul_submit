# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 16:23:10 by hyeondle          #+#    #+#              #
#    Updated: 2023/05/26 17:02:08 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	Account.cpp tests.cpp
INCLUDE	=	./

all		:	$(NAME)

$(NAME)	:
			$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all