SRC = *.c
# LIBS = -framework OpenGL -I$(HOME)/.brew/include/SDL2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
# LIBS = -framework OpenGL -I/usr/local/Cellar/sdl2 -L$(HOME)/.brew/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
NAME = mod1
LIBS = -framework OpenGL -I /usr/local/include/SDL2 -L/usr/local/lib -lSDL2  -D_THREAD_SAFE libftprintf.a
all:
	echo $(HOME)
	gcc $(SRC) $(LIBS) -o $(NAME)
