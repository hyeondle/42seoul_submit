# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 01:56:23 by hyeondle          #+#    #+#              #
#    Updated: 2023/05/26 17:02:06 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	Contact.cpp PhoneBook.cpp main.cpp
INCLUDE	=	./

all		:	$(NAME)

$(NAME)	:
			$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all