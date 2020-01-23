#include <stdio.h>
#include <SDL.h>
#include <OpenGL/gl.h>
#include "mod_h.h"

SDL_Window *win = NULL;

void initGLandSDL()
{
    // Инициализация SDL

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("Unable to init SDL, error.\n");
        exit(1);
    }

    // Включаем двойной буфер, настраиваем цвета

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

    win = SDL_CreateWindow("Mod1",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                           800, 600,
                           SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    SDL_GLContext glcontext = SDL_GL_CreateContext(win); // создаем контекст OpenGL

    if(win == NULL)
    { // если не получилось создать окно, то выходим
        exit(1);
    }

    // Инициализация OpenGL

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный
    glClearDepth(1.0);
    //    glDepthFunc(GL_LESS);
    //    glEnable(GL_DEPTH_TEST); // включаем тест глубины
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void endSDL()
{
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int main(int ac, char **av)
{
    // initGLandSDL();
    // SDL_Event event;
    // int running = 1;
	// glScalef(0.5f, 0.5f, 0.5f);
    // while (running)
    // {
    //     glClear(GL_COLOR_BUFFER_BIT);
    //     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        
    //     while ( SDL_PollEvent(&event) )
    //     {
    //         switch(event.type)
    //         {
    //             case SDL_QUIT:
    //                 running = 0;
    //                 break;
    //         }
    //     }
        
	// 	 // 1 1 0
	// 	 // 2 2 5
	// 	 // 1 2 7
	// 	 // 2 1 3
    //     glBegin(GL_POLYGON);
    //     glColor3f(1.0f, 0.0f, 0.0f);
    //     glVertex3f(0.0f, 0.0f, 0.0f);

	// 	glColor3f(1.0f, 1.0f, 1.0f);
    //     glVertex3f(1.0f, 0.0f, 0.0f);

	// 	glColor3f(0.0f, 1.0f, 0.0f);
    //     glVertex3f(1.0f, 1.0f, 0.0f);

    //     glColor3f(0.0f, 0.0f, 1.0f);
    //     glVertex3f(0.0f, 1.0f, 0.0f);

	// 	glColor3f(0.0f, 0.0f, 1.0f);
    //     glVertex3f(-0.5f, 0.5f, 0.0f);

	// 	glColor3f(0.0f, 0.0f, 1.0f);
    //     glVertex3f(-0.5f, -0.7f, 0.0f);

	// 	glColor3f(0.0f, 0.0f, 1.0f);
    //     glVertex3f(0.7f, -0.5f, 0.0f);

	// 	glColor3f(0.0f, 0.0f, 1.0f);
    //     glVertex3f(1.0f, 0.0f, 0.0f);

    //     glEnd();
    //     SDL_GL_SwapWindow(win);
    // }
	t_map map;
	int fd;

	fd = open(av[1], O_RDONLY);
	init_map(map.mp);
	read_map(fd, &map);
    init_x_y(&map);
	int i = 0;
    altitude_calculation(&map);
	while (i < MAP_SIZE)
	{
		ft_printf("%2d ", map.mp[i].op);
		if ((i + 1) % 100 == 0)
			write(1, "\n", 1);
		i++; 
	}
    return (0);
}