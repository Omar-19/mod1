# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btheia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 21:07:00 by flogan            #+#    #+#              #
#    Updated: 2020/07/05 02:56:57 by btheia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBS = -framework OpenGL -I$(HOME)/.brew/include/SDL2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
# LIBS = -framework OpenGL -I/usr/local/Cellar/sdl2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
# NAME = mod1
# LIBS =
# all:
# 	echo $(HOME)
# 	gcc $(SRC) $(LIBS) -o $(NAME)

ASM =			mod1
NAME =			$(ASM)
LIBFT_A =		libftprintf.a
LIBFT =			ft_printf/
HEADER =		include/mod_h.h
LIBFT_DIR_A =  	ft_printf/libftprintf.a
KEY = -Wno-deprecated-declarations -framework OpenGL -I /usr/local/include/SDL2 -lSDL2 -D_THREAD_SAFE $(LIBFT_DIR_A)

COMP =			gcc -g $(KEY) $(LIBS) -I include -I ft_printf/includes -c -o

OBJ_DIR =		obj/

ASM_DIR =		src/

ASM_SRC =   alg_water2.c \
			alg_watet.c \
			altitude_calculation.c \
			gnl.c \
			iso_met.c \
			main.c \
			read_map.c \

ASM_OBJ =			$(ASM_SRC:%.c=%.o)

OBJ =				$(ASM_OBJ)

SRC_PATH_ASM =		$(ASM_SRC:%=$(ASM_DIR)%)

SRC_PATH =			$(SRC_PATH_ASM)

OBJ_PATH_ASM =		$(addprefix $(OBJ_DIR), $(ASM_OBJ))

OBJ_PATH =			$(OBJ_PATH_ASM)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n"Create mod1"\\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH) $(HEADER)
				@gcc $(KEY) $(OBJ_PATH_ASM) $(LIBFT_DIR_A) -o $(ASM)
				# @gcc -L ~/.brew/lib -lSDL2 -lSDL2_ttf -I include/ -I ft_printf/includes/ ft_printf/libftprintf.a $(OBJ_PATH_DIS_ASM) -o $(DIS_ASM)

$(OBJ_PATH_ASM):			$(SRC_PATH_ASM)
							@$(MAKE) $(ASM_OBJ)

$(ASM_OBJ):				$(LIBFT_DIR_A) $(HEADER)
						@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
						@$(COMP) $(OBJ_DIR)$@ $(ASM_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)

color:.
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo Cleaned libft object files

fclean:			clean
				@/bin/rm -f $(NAME) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo Cleaned $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re color
