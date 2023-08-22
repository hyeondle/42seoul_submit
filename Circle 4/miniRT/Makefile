# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 18:31:48 by hyeondle          #+#    #+#              #
#    Updated: 2023/08/21 11:48:47 by hyejeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

LIBFT_DIR	=	./libft
LIBFT		=	./libft/libft.a

MLX_DIR		=	./minilibx/
MLX			=	./minilibx/libmlx.a

HEADERS_DIR	=	./includes/
HEADERS		=	draw.h\
				errors.h\
				ft_atof.h\
				ft_free.h\
				hit_object.h\
				init_map.h\
				map.h\
				object.h\
				parser.h\
				set_object.h\
				sets.h\
				trace.h\
				vector.h
HEADER		=	$(addprefix $(HEADERS_DIR), $(HEADERS))

SOURCE		=	main.c\
				draw.c\
				initializing/init_map.c\
				initializing/init_map2.c\
				initializing/init_map3.c\
				initializing/map.c\
				initializing/parser.c\
				initializing/check_param.c\
				initializing/check_param2.c\
				initializing/check_param3.c\
				objects/hit_cylinder.c\
				objects/hit_cylinder2.c\
				objects/hit_object.c\
				objects/object.c\
				objects/objects.c\
				objects/set_object.c\
				objects/set_object2.c\
				tracing/hit.c\
				tracing/phong_lighting.c\
				tracing/trace_ray.c\
				utils/errors.c\
				utils/ft_atof.c\
				utils/ft_free.c\
				vector/vector_basic_calculation.c\
				vector/vector_basic_calculation2.c\
				vector/vector_length.c\
				vector/vector_product_calculation.c\
				vector/vector_set.c

OBJECT			=	$(SOURCE:.c=.o)\

W_SIZE		=	-D WIDTH=1280 -D HEIGHT=720
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra $(W_SIZE)
LIBS		=	-L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCDS		=	-I $(HEADERS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

.c.o		:
				$(CC) $(FLAGS) $(INCDS) -c $< -o $(<:.c=.o)

all			:	$(NAME)

$(LIBFT)	:
				make -C $(LIBFT_DIR)
$(MLX)		:
				make -C $(MLX_DIR)
$(NAME)		:	$(OBJECT) $(LIBFT) $(MLX)
				$(CC) $(FLAGS) $(INCDS) $(OBJECT) $(LIBS) -o $(NAME)

clean		:
				rm -rf $(OBJECT)
				@make -C $(LIBFT_DIR) clean

fclean		:	clean
				rm -rf $(NAME)
				@make -C $(LIBFT_DIR) fclean

re			:
				@make fclean
				@make all

.PHONY		:	all clean fclean re
