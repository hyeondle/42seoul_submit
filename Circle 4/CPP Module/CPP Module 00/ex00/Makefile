# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 13:17:06 by hyeondle          #+#    #+#              #
#    Updated: 2023/05/26 17:02:03 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	megaphone.cpp

all		:	$(NAME)

$(NAME)	:
			$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all