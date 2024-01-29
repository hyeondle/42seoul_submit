# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 09:53:13 by hyeondle          #+#    #+#              #
#    Updated: 2024/01/13 09:53:26 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	main.cpp PmergeMe.cpp
INCD	=	./

all		:	$(NAME)

$(NAME)	:	$(SOURCE)
			$(CC) $(FLAGS) $(SOURCE) -I $(INCD) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all

.PHONY	:	all fclean re