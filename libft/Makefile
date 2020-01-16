# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btheia <btheia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/28 18:36:22 by angavrel          #+#    #+#              #
#    Updated: 2019/11/02 22:23:47 by btheia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES =	bit_out.c \
check_symbol.c \
del_dopfunction.c \
del_dopfunction2.c \
dop_func_float.c \
dop_function.c \
float_g.c \
float_e.c \
float_my.c \
float_umn.c \
float_umn_help.c \
ft_lib_char.c \
ft_lib_float.c \
ft_lib_hex_octa.c \
ft_lib_int.c \
ft_printf.c \
ft_uint64toa.c \
help_func.c \
help_func1.c \
help_function2.c \
help_function3.c \
help_function_float.c \
hex_help_func.c \
hex_octa_int.c \
main.c \
parameter_processing.c \
sum_funchelp.c \
sum_function.c \
new_float.c \
par_proc_help.c \
par_proc_help1.c \
par_proc_help2.c \
hex_help_func2.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/header.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean
