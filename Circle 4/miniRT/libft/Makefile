# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 16:03:02 by hyeondle          #+#    #+#              #
#    Updated: 2023/03/18 17:51:24 by hyeondle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

BASIC_DIR		=	./basic/
BASIC			=	libftbasic.a
BASIC_INC		=	$(BASIC_DIR)

PF_DIR			=	./ft_printf/
PF				=	libftprintf.a
PF_INC			=	$(PF_DIR)

GNL_DIR			=	./get_next_line/
GNL				=	libftgetnextline.a
GNL_INC			=	$(GNL_DIR)

TEMP_DIR		=	temp

LIBS			=	$(BASIC) $(PF) $(GNL)
INCS			=	-I $(BASIC_INC) -I $(PF_INC) -I $(GNL_INC)

CC				=	cc
LIB				=	ar -rcs
RM				=	rm -f

all				:	$(NAME)

$(BASIC_DIR)$(BASIC)		:
				@make -C $(BASIC_DIR)

$(PF_DIR)$(PF)			:
				@make -C $(PF_DIR)

$(GNL_DIR)$(GNL)			:
				@make -C $(GNL_DIR)

$(NAME)			:	$(BASIC_DIR)$(BASIC) $(PF_DIR)$(PF) $(GNL_DIR)$(GNL)
					@mkdir -p $(TEMP_DIR)
					cp $(BASIC_DIR)$(BASIC) $(TEMP_DIR)
					cp $(PF_DIR)$(PF) $(TEMP_DIR)
					cp $(GNL_DIR)$(GNL) $(TEMP_DIR)
					cd $(TEMP_DIR) && ar -x $(BASIC) && ar -x $(PF) && ar -x $(GNL)
					$(LIB) $(NAME) $(TEMP_DIR)/*.o
					rm -rf $(TEMP_DIR)
					

clean :
	@make -C $(BASIC_DIR) clean
	@make -C $(PF_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@$(RM) $(BASIC_DIR)$(BASIC)
	@$(RM) $(PF_DIR)$(PF)
	@$(RM) $(GNL_DIR)$(GNL)
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re