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
                           1000, 1000,
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

int	color_red(int h_max, int h)
{
	float step = (191 - 136) / h_max;
	return (136 + (int)(h * step));
}

int main(int ac, char **av)
{

	t_map map;
	int fd;
	int red;

	fd = open(av[1], O_RDONLY);
	init_map(map.mp);
	read_map(fd, &map);
    init_x_y(&map);
    null_border(&map);
	int i = 0;
    altitude_calculation(&map);
	while (i < MAP_SIZE)
	{
		// ft_printf("%2d ", map.mp[i].z);
		// if ((i + 1) % 100 == 0)
			// write(1, "\n", 1);
        if (map.mp[i].z)
            ft_printf("%d %d %d\n", i / 100, i % 100, map.mp[i].z);
		i++;
	}
    write(1, "\n", 1);
    write(1, "water\n", 6);
    // initGLandSDL();
    SDL_Event event;
    int running = 1;
	// glScalef(0.005f, 0.005f, 0.005f);
    i = 0;
	int j = 0;
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
	// 	i = 0;
	// 	j = 0;
    //     while (i < 99)
    //     {
	// 		j = -1;
	// 		while (++j < 99)
	// 		{
	// 			glBegin(GL_POLYGON);
	// 			glColor3ub(color_red(25, map.mp[i * 100 + j].z), 191, 69);
	// 			glVertex3f((0.0f + (float)(i)), (0.0f + (float)(j)), 0.0f);

	// 			glColor3ub(color_red(25, map.mp[(i + 1) * 100 + j].z), 191, 69);
	// 			glVertex3f((1.0f + (float)(i)), (0.0f + (float)(j)), 0.0f);

	// 			glColor3ub(color_red(25, map.mp[(i + 1) * 100 + (j + 1)].z), 191, 69);
	// 			glVertex3f((1.0f + (float)(i)), (1.0f + (float)(j)), 0.0f);

	// 			glColor3ub(color_red(25, map.mp[i * 100 + (j + 1)].z), 191, 69);
	// 			glVertex3f((0.0f + (float)(i)), (1.0f + (float)(j)), 0.0f);
	// 			glEnd();
	// 		}
	// 		i += 1;
    //     }
    //     glEnd();
	// 	SDL_GL_SwapWindow(win);
	// 	// glColor3f(0.0f, 0.0f, 1.0f);
    //     // glVertex3f(-0.5f, 0.5f, 0.0f);

	// 	// glColor3f(0.0f, 0.0f, 1.0f);
    //     // glVertex3f(-0.5f, -0.7f, 0.0f);

	// 	// glColor3f(0.0f, 0.0f, 1.0f);
    //     // glVertex3f(0.7f, -0.5f, 0.0f);

	// 	// glColor3f(0.0f, 0.0f, 1.0f);
    //     // glVertex3f(1.0f, 0.0f, 0.0f);

    // }
    j = 0;
    while (j < 3)
    {
        i = 0;
        if (j == 2)
        {
            while (i < MAP_SIZE)
            {
                ft_printf("%2.0f", map.mp[i].wh);
                if ((i + 1) % 100 == 0)
                    write(1, "\n", 1);
                i++;
            }
            write(1, "bef calc\n", 8);
        }

        up_water(map.mp);
        wave_calc(map.mp);
        update_water(map.mp);
        if (j == 2)
        {
            write(1, "after\n", 6);
            i = 0;
            while (i < MAP_SIZE)
            {
                ft_printf("%2.0f ", map.mp[i].wh);
                if ((i + 1) % 100 == 0)
                    write(1, "\n", 1);
                i++;
            }
            write(1, "\n\n\n\n", 4);
        }
        j++;
        // sleep(2);
    }
    return (0);
}
