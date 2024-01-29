# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 22:11:35 by hyeondle          #+#    #+#              #
#    Updated: 2023/11/04 22:51:26 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mutantstack

CXX		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	main.cpp
INCD	=	./

all		:	$(NAME)

$(NAME)	:	$(SOURCE)
			$(CXX) $(FLAGS) $(SOURCE) -I $(INCD) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all

.PHONY	:	all fclean re