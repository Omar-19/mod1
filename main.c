#include <stdio.h>
#include <SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
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
       glDepthFunc(GL_LESS);
    // glEnable(GL_DEPTH_TEST); // включаем тест глубины
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
	float step = (float)(191 - 136) / (float)h_max;
	// ft_printf("col %d step %lf max h %d cur_h %d\n", 136 + (int)(h * step), step, h_max, h);
	return (136 + (int)(h * step));
}

void water_f(int key, t_map *map)
{
	if (key == 0 || key == 1)
		up_water(map->mp, key);
	wave_calc(map->mp);
	update_water(map->mp);
}

void	water_pol(int i, int j, t_map *map)
{
	int x;
	int y;


	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);

	//vverh
	x = (0.0f + (float)(i) - ROW_SIZE/2);
	y = (0.0f + (float)(j) - ROW_SIZE/2);
	if ((float)map->mp[i * ROW_SIZE + j].wh + (float)map->mp[i * ROW_SIZE + j].z > (float)map->mp[i * ROW_SIZE + j].z)
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + j].wh + (float)map->mp[i * ROW_SIZE + j].z);

	x = (1.0f + (float)(i) - ROW_SIZE/2);
	y = (0.0f + (float)(j) - ROW_SIZE/2);
	if ((float)map->mp[(i + 1) * ROW_SIZE + j].wh + (float)map->mp[(i + 1) * ROW_SIZE + j].z > (float)map->mp[(i + 1) * ROW_SIZE + j].z)
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + j].wh + (float)map->mp[(i + 1) * ROW_SIZE + j].z);
	// 	glColor3ub(0, 0, 255);
	// else
	// 	glColor3ub(0, 255, 0);

	x = (1.0f + (float)(i) - ROW_SIZE/2);
	y = (1.0f + (float)(j) - ROW_SIZE/2);

	if ((float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z > (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z)
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	// 	glColor3ub(0, 0, 255);
	// else
	// 	glColor3ub(0, 255, 0);
	// glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (0.0f + (float)(i) - ROW_SIZE/2);
	y = (1.0f + (float)(j) - ROW_SIZE/2);
	if ((float)map->mp[i * ROW_SIZE + (j + 1)].wh + (float)map->mp[i * ROW_SIZE + (j + 1)].z > (float)map->mp[i * ROW_SIZE + (j + 1)].z)
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].wh + (float)map->mp[i * ROW_SIZE + (j + 1)].z);
	// 	glColor3ub(0, 0, 255);
	// else
	// 	glColor3ub(0, 255, 0);
	// glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].wh + (float)map->mp[i * ROW_SIZE + (j + 1)].z);
	glEnd();
	glBegin(GL_POLYGON);
	//right
	if (i == 0 || i == ROW_SIZE - 2 || j == 0 || j == ROW_SIZE - 2){
		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].wh + (float)map->mp[i * ROW_SIZE + (j + 1)].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
		//front
		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + j].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + j].wh + (float)map->mp[(i + 1) * ROW_SIZE + j].z);

		//left
		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + j].wh + (float)map->mp[(i + 1) * ROW_SIZE + j].z);

		x = (1.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[(i + 1) * ROW_SIZE + j].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + j].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + j].wh + (float)map->mp[i * ROW_SIZE + j].z);

		//back
		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + j].wh + (float)map->mp[i * ROW_SIZE + j].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (0.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + j].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].z);

		x = (0.0f + (float)(i) - ROW_SIZE/2);
		y = (1.0f + (float)(j) - ROW_SIZE/2);
		glVertex3f(x, y, 0.0f + (float)map->mp[i * ROW_SIZE + (j + 1)].wh + (float)map->mp[i * ROW_SIZE + (j + 1)].z);
	}
	glEnd();

}


int main(int ac, char **av)
{

	t_map map;
	int fd;
	int red;

	fd = open(av[1], O_RDONLY);
	map.mp = (t_point *)malloc(sizeof(t_point) * MAP_SIZE);
	map.points = NULL;
	init_map(map.mp);
	read_map(fd, &map);
	null_border(&map);
	int i = 0;

	altitude_calculation(&map);
	initGLandSDL(); //#tut
	// glEnable(GL_DEPTH_TEST);
	SDL_Event event;
	int running = 1;

	i = 0;
	int j = 0;
	float plus = 0.002;
	glScalef(plus * 2, plus * 2, plus * 2);
	// glEnable(GL_DEPTH_TEST);
	// map.ar = 1; волна которая идет сверху
	// map.size_a = 100;
	// map.start = -1;
	// add_wave(&map);
	float x;
	float y;
	map.rain_s = 3;
	double povyx = 0;
	double povyx_d = 0;
	double povz = 65;
	double povz_d = 0;
	// glRotatef(pov, 1, 0, 0);
	int l = 0;
	int water = 0;
	gluLookAt(60.0, 60.0, 30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); //2 * sqrt(60)
	glRotatef(65, 0, 0, 1);
	map.flow = 0;
	while (running) //running
	{

		while ( SDL_PollEvent(&event) )
		{
			switch (event.type)
			{
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_w)
					{
						povyx_d = (event.key.keysym.sym == SDLK_w) ? -2.0: 2.0;
						povyx += povyx_d;
						if (povyx < 4 && povyx >= -30)
							glRotatef(povyx_d, 1, -1, 0);

					}
					if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)
					{
						povz_d = (event.key.keysym.sym == SDLK_a) ? 2.0: -2.0;
						povz += povz_d;
						if (povz < 133 && povz >= -45)
							glRotatef(povz_d, 0, 0, 1);
					}
					if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_q)
					{
						water = (event.key.keysym.sym == SDLK_e) ? 1 : 0;
					}
					if (event.key.keysym.sym == SDLK_h || event.key.keysym.sym == SDLK_l)
					{
						map.flow = (event.key.keysym.sym == SDLK_h) ? 0 : 1;
						water_f(map.flow, &map);
					}
					break;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// glPushMatrix();
		// rad_fi = (ugl_fi * (pi / 180));
		// rad_tet = (ugl_tet * (pi / 180));
		// gluLookAt(radious * sin(rad_tet) * cos(rad_fi),radious * sin(rad_tet) * sin(rad_fi), radious * cos(rad_tet), 0.0, 0.0, 0.0, 0, 0, 1.0);
		// glPopMatrix();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//
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
				if (map.mp[i * ROW_SIZE + j].z)
					glColor3ub(color_red(map.max_h, map.mp[i * ROW_SIZE + j].z), 191, 69);
				else
					glColor3ub(255, 0, 0);

				glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + j].z);
				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (0.0f + (float)(j) - ROW_SIZE/2);
				if (map.mp[i * ROW_SIZE + j].z)
					glColor3ub(color_red(map.max_h, map.mp[(i + 1) * ROW_SIZE + j].z), 191, 69);
				else
					glColor3ub(255, 0, 0);


				glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + j].z);
				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				if (map.mp[i * ROW_SIZE + j].z)
					glColor3ub(color_red(map.max_h, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z), 191, 69);
				else
					glColor3ub(255, 0, 0);

				glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + (j + 1)].z);
				x = (0.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				if (map.mp[i * ROW_SIZE + j].z)
					glColor3ub(color_red(map.max_h, map.mp[i * ROW_SIZE + (j + 1)].z), 191, 69);
				else
					glColor3ub(255, 0, 0);

				glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + (j + 1)].z);
				glEnd();
				if (water == 1)
					water_pol(i, j, &map);
			}
			i += 1;
		}

		i = 0;
		j = 0;
		if (0)
		{
			while (i < ROW_SIZE - 1)
			{
				j = -1;
				while (++j < ROW_SIZE - 1)
				{
					// x = (0.0f + (float)(i) - ROW_SIZE/2);
					// y = (0.0f + (float)(j) - ROW_SIZE/2);
					// glBegin(GL_POLYGON);
					// glColor3ub(0, 0, 255);
					// glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + j].wh + (float)map.mp[i * ROW_SIZE + j].z);

					// x = (1.0f + (float)(i) - ROW_SIZE/2);
					// y = (0.0f + (float)(j) - ROW_SIZE/2);
					// glColor3ub(0, 0, 255);
					// glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + j].wh + (float)map.mp[i * ROW_SIZE + j].z);

					// x = (1.0f + (float)(i) - ROW_SIZE/2);
					// y = (1.0f + (float)(j) - ROW_SIZE/2);
					// glColor3ub(0, 0, 255);
					// glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + (j + 1)].wh +(float)map.mp[(i + 1) * ROW_SIZE + (j + 1)].z);

					// x = (0.0f + (float)(i) - ROW_SIZE/2);
					// y = (1.0f + (float)(j) - ROW_SIZE/2);
					// glColor3ub(0, 0, 255);
					// glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + (j + 1)].wh + (float)map.mp[i * ROW_SIZE + (j + 1)].z);

					// glEnd();
					water_pol(i, j, &map);
				}
				i += 1;
			}
		}
		// update_water(map.mp);
		glEnd();

		SDL_GL_SwapWindow(win);
	} //tuutt

	return (0);
}
