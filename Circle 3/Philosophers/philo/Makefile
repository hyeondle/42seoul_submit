# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 22:41:44 by hyeondle          #+#    #+#              #
#    Updated: 2023/03/15 11:16:21 by Linsio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philo



SOURCES			=	main.c\
					init.c\
					handler.c\
					free.c\
					utils.c\
					philo_status.c\
					philo_do.c\
					philo_fork.c\
					mutex_checker.c\
					mutex_checker2.c\

OBJECTS			=	${SOURCES:.c=.o}

CC				= cc
FLAGS			= -Wall -Werror -Wextra

.c.o	:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ./

all : $(NAME)

$(NAME)	:	$(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean	:
			-rm $(OBJECTS)

fclean	:	clean
			-rm $(NAME)

re		:	fclean all


.PHONY : all clean fclean re
