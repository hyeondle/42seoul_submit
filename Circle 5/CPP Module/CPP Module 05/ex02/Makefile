# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 12:10:25 by hyeondle          #+#    #+#              #
#    Updated: 2023/10/27 13:52:57 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Bureaucrat

CC		=	c++
FLAGS	=	-std=c++98 -Wall -Wextra -Werror

SOURCE	=	main.cpp Bureaucrat.cpp AForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp
INCD	=	./

all		:	$(NAME)

$(NAME)	:	$(SOURCE)
			$(CC) $(FLAGS) $(SOURCE) -I $(INCD) -o $(NAME)

fclean	:
			-rm $(NAME)

re		:	fclean all

.PHONY	:	all fclean re