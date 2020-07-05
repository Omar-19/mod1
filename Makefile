SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

GCC = gcc -Wall -Wextra -Werror
NAME = mod1
SRCS = 		alg_water2.c \
			alg_watet.c \
			altitude_calculation.c \
			gnl.c \
			iso_met.c \
			main.c \
			read_map.c \
			water_print.c \
			main_h1.c \
			main_h2.c \

HEAD = -I$(INCDIR)

MAKES = ./ft_printf/libftprintf.a
LIB := -framework OpenGL -lSDL2 -D_THREAD_SAFE ./ft_printf/libftprintf.a
HEAD += -I /usr/local/include/SDL2

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS = $(addprefix $(OBJDIR), $(SRCS:.c=.d))

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(GCC) -Wno-deprecated-declarations -MD -o $@ -c $(HEAD) $<

$(MAKES):
	make -C  ft_printf/

-include $(DEPENDS)

$(NAME): $(MAKES) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(DEPENDS)
	make -C ft_printf/ fclean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf/ fclean

re: fclean all

.PHONY: clean fclean re
