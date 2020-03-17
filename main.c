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
    map.mp = (t_point *)malloc(sizeof(t_point) * MAP_SIZE);
	init_map(map.mp);
	read_map(fd, &map);
    init_x_y(&map);
    null_border(&map);
	int i = 0;
    altitude_calculation(&map);
	while (i < MAP_SIZE)
	{
		ft_printf("%2d ", map.mp[i].z);
		if ((i + 1) % ROW_SIZE == 0)
			write(1, "\n", 1);
		i++;
	}
    initGLandSDL();
    SDL_Event event;
    int running = 1;
	glScalef(0.0005f * 2, 0.0005f * 2, 0.0005f * 2);
    i = 0;
	int j = 0;

    // map.ar = 1; волна которая идет сверху
    // map.size_a = 100;
    // map.start = -1;
    // add_wave(&map);
	float x;
	float y;
	float z;
    map.rain_s = 3;
    while (running)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        while ( SDL_PollEvent(&event) )
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
		i = 0;
		j = 0;
        while (i < ROW_SIZE - 1)
        {
			j = -1;
			while (++j < ROW_SIZE - 1)
			{
				x = (0.0f + (float)(i) - ROW_SIZE/2);
				y = (0.0f + (float)(j) - ROW_SIZE/2);
				glBegin(GL_POLYGON);
				glColor3ub(color_red(25, map.mp[i * ROW_SIZE + j].z), 191, 69);
				glVertex3f(iso_x(x, y, map.mp[i * ROW_SIZE + j].z / map.max_h, 0), iso_x(x, y, map.mp[i * ROW_SIZE + j].z / map.max_h, 1), 0.0f + map.mp[i * ROW_SIZE + j].z / map.max_h);

				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (0.0f + (float)(j) - ROW_SIZE/2);
				glColor3ub(color_red(25, map.mp[(i + 1) * ROW_SIZE + j].z), 191, 69);
				glVertex3f(iso_x(x, y, map.mp[(i + 1) * ROW_SIZE + j].z / map.max_h, 0), iso_x(x, y, map.mp[(i + 1) * ROW_SIZE + j].z / map.max_h, 1), 0.0f + map.mp[(i + 1) * ROW_SIZE + j].z / map.max_h);

				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				glColor3ub(color_red(25, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z), 191, 69);
				glVertex3f(iso_x(x, y, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z / map.max_h, 0), iso_x(x, y, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z / map.max_h, 1), 0.0f + map.mp[(i + 1) * ROW_SIZE + (j + 1)].z / map.max_h);

				x = (0.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				glColor3ub(color_red(25, map.mp[i * ROW_SIZE + (j + 1)].z), 191, 69);
				glVertex3f(iso_x(x, y, map.mp[i * ROW_SIZE + (j + 1)].z / map.max_h, 0), iso_x(x, y, map.mp[i * ROW_SIZE + (j + 1)].z / map.max_h, 1), 0.0f + map.mp[i * ROW_SIZE + (j + 1)].z / map.max_h);
				glEnd();
                // if (map.mp[i * ROW_SIZE + j].wh && map.mp[(i + 1) * ROW_SIZE + j].wh && map.mp[(i + 1) * ROW_SIZE + (j + 1)].wh && map.mp[i * ROW_SIZE + (j + 1)].wh)
                // {
                //     glBegin(GL_POLYGON);
                //     glColor3ub(0, 0, 255);
                //     glVertex3f((0.0f + (float)(i) - ROW_SIZE/2), (0.0f + (float)(j) - ROW_SIZE/2), 0.0f);

                //     glColor3ub(0, 0, 255);
                //     glVertex3f((1.0f + (float)(i) - ROW_SIZE/2), (0.0f + (float)(j) - ROW_SIZE/2), 0.0f);

                //     glColor3ub(0, 0, 255);
                //     glVertex3f((1.0f + (float)(i) - ROW_SIZE/2), (1.0f + (float)(j) - ROW_SIZE/2), 0.0f);

                //     glColor3ub(0, 0, 255);
                //     glVertex3f((0.0f + (float)(i) - ROW_SIZE/2), (1.0f + (float)(j) - ROW_SIZE/2), 0.0f);
                //     glEnd();
                // }
                
			}
			i += 1;
        }
        // sleep(2);
        up_water(map.mp);
        // add_rain(&map);
        // i = 0;
        // while (i < MAP_SIZE)
        // {
        //     ft_printf("%2d ", map.mp[i].wh);
        //     if ((i + 1) % 100 == 0)
        //         write(1, "\n", 1);
        //     i++;
        // }
        // write(1, "\n", 1);
        // write(1, "water\n", 6);
        wave_calc(map.mp);
        update_water(map.mp);
        glEnd();
		SDL_GL_SwapWindow(win);
		// glColor3f(0.0f, 0.0f, 1.0f);
        // glVertex3f(-0.5f, 0.5f, 0.0f);

		// glColor3f(0.0f, 0.0f, 1.0f);
        // glVertex3f(-0.5f, -0.7f, 0.0f);

		// glColor3f(0.0f, 0.0f, 1.0f);
        // glVertex3f(0.7f, -0.5f, 0.0f);

		// glColor3f(0.0f, 0.0f, 1.0f);
        // glVertex3f(1.0f, 0.0f, 0.0f);

    }
    
    return (0);
}
