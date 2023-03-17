# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 14:42:31 by hyeondle          #+#    #+#              #
#    Updated: 2022/10/21 14:20:34 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

LIBFT_DIR			= ./libft/
LIBFT				= $(LIBFT_DIR)libft.a

MLX_DIR			= ./minilibx/
MLX				= $(MLX_DIR)libmlx.a

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./source/

CC				= cc
FLAGS			= -Wall -Werror -Wextra -O3
LIBS			= -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCDS			= -I ./includes/ -I ./libft/ -I ./minilibx/

RM				=	rm -f


$(NAME)	: $(NAME) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(INCDS) $(SOURCES_DIR)*.c $(LIBS) -o $(NAME)

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(MLX) :
	@make -C $(MLX_DIR)

all : $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean : clean
	@rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
