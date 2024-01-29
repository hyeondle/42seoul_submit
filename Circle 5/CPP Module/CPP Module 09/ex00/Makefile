# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 09:53:18 by hyeondle          #+#    #+#              #
#    Updated: 2024/01/13 09:53:22 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	main.cpp BitcoinExchange.cpp
INCD	=	./

all		:	$(NAME)

$(NAME)	:	$(SOURCE)
			$(CC) $(FLAGS) $(SOURCE) -I $(INCD) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all

.PHONY	:	all fclean re