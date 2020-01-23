# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 10:05:49 by sinkosi           #+#    #+#              #
#    Updated: 2019/09/16 11:25:03 by sinkosi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################
#	NAME			#
#################################
NAME	= libftls.a

#########################
#	COLOURS		#
#########################
NOC		= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
#COLOUR LIST BELOW WITH BOLD ON
RED		= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
MAGENTA		= \033[1,35m
CYAN		= \033[1;36m
WHITE		= \033[1;0m

OUTPUT	= 	@echo	"$(GREEN)$(NAME) has been created."\
			"$(BLUE)\nThis library is the intellectual property of"\
			"$(CYAN)\nSIBONELO NKOSI (SINKOSI) & WETHINKCODE_ (NPC)$(WHITE)"\

#########################
#	PATHS		#
#########################
LIBFT_A		= libft.a

INC_PATH	= includes/
SRCS_PATH	= srcs
OBJ_PATH	= obj/
LIBFT_PATH	= ./libft/

#############################################
#	COMPILER
######################################
CC		= gcc
CC1		= clang
FLAGS		= -Wall -Werror -Wextra

#########################
#	HEADERS		#
#########################

FT_LS_H	= -I ./includes/
LIBFT_H		= -I ./$(LIBFT_PATH)/includes/

#################################
#	FILES			#
#################################
SRCS_NAME	=	ft_dir_strcmp.c		\
				ft_flag_recursive.c	\
				ft_ls_flag_set.c	\
				ft_get_time.c		\
				ft_get_user.c		\
				ft_list_run.c		\
				ft_ls_p_long_list.c	\
				ft_ls_p_permission.c\
				ft_ls_print.c		\
				ft_ls_run_op.c			\
				ft_ls_strlen.c		\
				ft_rev_list.c		\
				ft_sort_list.c		\
				ft_strchrcat.c		\
				ft_time_cmp.c		\


OBJ		= $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:%.c=%.o))
################################################
#	LIBRARIES
###############################################

LIBFT		= $(LIBFT_PATH) -lft

##############################################
#	MAKE RULES
############################################

all:	$(NAME)

$(NAME):	$(OBJ)
		@make all -C $(LIBFT_PATH)/
		@#cp $(LIBFT_PATH) $(LIBFT_A) .
		@#mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(OBJ) $(LIBFT_PATH)/obj/*.o
		@ranlib $(NAME)
		$(OUTPUT)
		@clang -Wall -Wextra -Werror srcs/ft_ls.c libftls.a -o ft_ls
		

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir	-p $(OBJ_PATH)
	@$(CC1) -I $(INC_PATH) -o $@ -c $<

clean	:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean	: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@rm -rf ./ft_ls

re:	fclean all

.PHONY:	all, clean, fclean, re