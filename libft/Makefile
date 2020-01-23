# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinkosi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 10:06:06 by sinkosi           #+#    #+#              #
#    Updated: 2019/07/28 10:33:21 by sinkosi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								LIBRARY
################################################################################
NAME := libft.a
#LIBRARY NAME ^^^
################################################################################
#								DIRECTORIES
################################################################################
INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := obj
#OBJECTS DIRECTORY ^^^
################################################################################
#								FILES
################################################################################

SRC :=		ft_islower.c	\
			ft_isupper.c	\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isblank.c	\
			ft_isspace.c	\
			ft_isascii.c	\
			ft_isgraph.c	\
			ft_ispunct.c	\
			ft_iscntrl.c	\
			ft_isprint.c	\
			ft_isxdigit.c	\
			ft_isimax.c		\
			ft_isimin.c		\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_tochar.c		\
			ft_tostr.c		\
			ft_str_is_lowercase.c	\
			ft_str_is_uppercase.c	\
			ft_str_is_alpha.c		\
			ft_str_is_numeric.c		\
			ft_str_is_xnumeric.c	\
			ft_str_is_alnum.c		\
			ft_str_is_printable.c	\
		  ft_memset.c		\
		  ft_bzero.c		\
		  ft_memalloc.c		\
		  ft_memdel.c		\
		  ft_memcpy.c		\
		  ft_memccpy.c		\
		  ft_memmove.c		\
		  ft_memchr.c		\
		  ft_memcmp.c		\
		  ft_strlen.c		\
		  ft_strcpy.c		\
		  ft_strncpy.c		\
		  ft_strlcpy.c		\
		  ft_strcat.c		\
		  ft_strncat.c		\
		  ft_strlcat.c		\
		  ft_strchr.c		\
		  ft_strrchr.c		\
		  ft_strlchr.c		\
		  ft_strchr_bool.c	\
		  ft_strstr.c		\
		  ft_strnstr.c		\
		  ft_strlstr.c		\
		  ft_strcasestr.c	\
		  ft_strcmp.c		\
		  ft_strncmp.c		\
		  ft_strcasecmp.c	\
		  ft_strncasecmp.c	\
  		  ft_strnew.c		\
  		  ft_strdel.c		\
  		  ft_strclr.c		\
 		  ft_strdup.c		\
		  ft_strndup.c		\
		  ft_strequ.c		\
  		  ft_strnequ.c		\
		  ft_strreverse.c	\
			ft_div_mod.c		\
			ft_factorial.c		\
			ft_fibonacci.c		\
			ft_is_prime.c		\
			ft_find_next_prime.c\
			ft_power.c			\
			ft_sqrt.c			\
			ft_ultimate_div_mod.c\
			ft_vector.c			\
			ft_fabs.c			\
			ft_sine.c			\
		  ft_atoi.c			\
  		  ft_striter.c		\
  		  ft_striteri.c		\
  		  ft_strmap.c		\
  		  ft_strmapi.c		\
		  ft_strsub.c		\
		  ft_strjoin.c		\
		  ft_strtrim.c		\
		  ft_strtrim_delim.c\
		  ft_strsplit.c		\
		  ft_numlen.c		\
		  ft_itoa.c			\
		  ft_putchar.c		\
		  ft_putstr.c		\
		  ft_putendl.c		\
		  ft_putnbr.c		\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl_fd.c	\
		  ft_putnbr_fd.c	\
		  ft_lstnew.c		\
		  ft_lstdelone.c	\
		  ft_lstdel.c		\
		  ft_lstadd.c		\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_strlowcase.c	\
		  ft_strupcase.c	\
		  ft_strcapitalize.c	\
		  ft_swap.c			\
		  ft_numlen_base.c	\
		  ft_itoa_base.c	\
		  ft_putnbr_base.c	\
		  ft_atoi_base.c	\
		  ft_arraydup.c		\
		  get_next_line.c	\
		  ft_atoi_base.c	\
		  ft_convert.c		\
		  ft_flag_check.c		\
		  ft_flag_hash.c		\
		  ft_flag_plus.c		\
		  ft_flag_precision.c	\
		  ft_flag_reset.c		\
		  ft_flag_space.c		\
		  ft_flag_set.c			\
		  ft_flag_size.c		\
		  ft_flag_width.c		\
		  ft_handler_b_binary.c	\
		  ft_handler_c_char.c	\
		  ft_handler_d_int.c	\
		  ft_handler_o_octal.c	\
		  ft_handler_p_pointer.c\
		  ft_handler_s_str.c	\
		  ft_handler_u_unsigned_int.c	\
		  ft_handler_x_hexadecimal.c	\
		  ft_handler_f_float.c	\
		  ft_handler_convert.c			\
		  ft_print_b_binary.c	\
		  ft_print_c_char.c		\
		  ft_print_d_int.c		\
		  ft_printf.c			\
		  ft_print_mod.c		\
		  ft_print_f_float.c	\
		  ft_print_lf_float.c	\
		  ft_print_o_octal.c	\
		  ft_print_out.c		\
		  ft_print_p_pointer.c	\
		  ft_print_s_str.c		\
		  ft_print_ws_str.c		\
		  ft_print_u_unsigned_int.c	\
		  ft_print_x_hexadecimal.c	\
		  ft_ltoa_base.c		\
		  ft_putwchar.c			\
		  ft_putwchar_fd.c		\
		  ft_putwstr.c			\
		  ft_putwstr_fd.c		\
		  ft_power_ten.c		\
		  ft_round_bool.c			


#ADD SOURCE FILES HERE ^^^
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
################################################################################
#								COMPILER
################################################################################
CFLAGS := -Wall -Werror -Wextra
#FLAGS^^^
CC := clang $(CFLAGS)
################################################################################
#								RULES
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	$(START)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	$(OUTPUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)$(NAME) OBJECTS CLEANED HAVE BEEN DELETED$(WHITE)"

fclean: clean
	@rm -f $(NAME) a.out
	@echo "$(RED)OBJECTS AND LIBFT.A HAVE BEEN CLEANED$(WHITE)"

re: fclean all

################################################################################
#								ADDITIONAL STUFF
################################################################################

.PHONY := all clean fclean re
#PHONY^^^

###############################################################################
#COLOURS
################################
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

################################################################################
OUTPUT	= 	@echo	"$(GREEN)$(NAME) has been created."\
			"$(BLUE)\nThis library is the intellectual property of"\
			"$(CYAN)\nSIBONELO NKOSI (SINKOSI) & WETHINKCODE_ (NPC)$(WHITE)"\

START	=	@echo "$(GREEN)BUILDING LIBFT LIBRARY$(WHITE)"\
		"$(BLUE)PLEASE BE PATIENT$(WHITE)"
