SRC = *.c
LIBS = -framework OpenGL -I$(HOME)/.brew/include/SDL2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
# LIBS = -framework OpenGL -I/usr/local/Cellar/sdl2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
NAME = mod1

all:
	echo $(HOME)
	gcc $(SRC) $(LIBS) -o $(NAME)
