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
	else if (key == 2)
		add_wave(map);
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


void	rain_info(t_map *map, int key)
{
	map->start = -1;
	map->size_a = MAP_SIZE;
	if (key == 49)
	{
		map->ar = 1;
		map->size_a = ROW_SIZE * 3;
	}
	else if (key == 50)
		map->ar = 2;
	else if (key == 51)
		map->ar = 3;
	else if (key == 52)
	{
		map->start = MAP_SIZE - ROW_SIZE * 3;
		map->ar = 4;
	}
}

void getNewCol(double max, double z, double *rgb)
{
	double proc;

	proc = z / max;
	if (z == 0)
	{
		rgb[0] = 0;
		rgb[1] = 255;
		rgb[2] = 0;
		return;
	}
	if (proc <= 0.05)
	{
		rgb[0] = 0;
		rgb[1] = 255;
		rgb[2] = 0;
	}
	if (0.05 < proc && proc <= 0.31)
	{
		rgb[0] = 0;
		rgb[1] = 204;
		rgb[2] = 0;
	}
	// if (0.21 < proc && proc <= 0.39)
	// {
	// 	rgb[0] = 0;
	// 	rgb[1] = 153;
	// 	rgb[2] = 0;
	// }
	if (0.31 < proc && proc <= 0.56)
	{
		rgb[0] = 51;
		rgb[1] = 102;
		rgb[2] = 0;
	}
	if (0.56 < proc && proc <= 0.65)
	{
		rgb[0] = 153;
		rgb[1] = 153;
		rgb[2] = 0;
	}
	if (0.65 < proc && proc <= 0.80)
	{
		rgb[0] = 204;
		rgb[1] = 102;
		rgb[2] = 0;
	}
	if (0.80 < proc && proc <= 0.98)
	{
		rgb[0] = 255;
		rgb[1] = 153;
		rgb[2] = 51;
	}
	if (0.98 < proc)
	{
		rgb[0] = 255;
		rgb[1] = 229;
		rgb[2] = 204;
	}
}

int main(int ac, char **av)
{

	t_map map;
	int fd;
	int red;
	double povyx = 0;
	double povyx_d = 0;
	double povz = 65;
	double povz_d = 0;
	double rgb[3];
	int water = 0;
	SDL_Event event;
	int running = 1;
	float x;
	float y;
	int i = 0;
	int j = 0;

	if (ac != 2)
	{
		ft_printf("Usage: mod1 [map file]");
		exit(0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(0);
	if ((map.mp = (t_point *)malloc(sizeof(t_point) * MAP_SIZE)) == NULL)
		exit(0);
	map.points = NULL;
	init_map(map.mp);
	read_map(fd, &map);
	null_border(&map);


	altitude_calculation(&map);
	initGLandSDL();


	glScalef(0.002 * 2, 0.002 * 2, 0.002 * 2);
	gluLookAt(60.0, 60.0, 30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); //2 * sqrt(60)
	glRotatef(65, 0, 0, 1);

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
						water = (event.key.keysym.sym == SDLK_e) ? 1 : 0;
					if (event.key.keysym.sym == SDLK_h || event.key.keysym.sym == SDLK_l)
					{
						map.flow = (event.key.keysym.sym == SDLK_h) ? 0 : 1;
						water_f(map.flow, &map);
					}
					if (event.key.keysym.sym == SDLK_u)
						water_f(2, &map);
					if (event.key.keysym.sym == SDLK_r)
						map.flow = 4;
					if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_4)
						rain_info(&map, event.key.keysym.sym);
					break;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		(map.flow == 4) ? add_rain(&map) : 0;
		i = -1;
		while (++i < ROW_SIZE - 1)
		{
			j = -1;
			while (++j < ROW_SIZE - 1)
			{
				x = (0.0f + (float)(i) - ROW_SIZE/2);
				y = (0.0f + (float)(j) - ROW_SIZE/2);
				glBegin(GL_POLYGON);

				// if (map.mp[i * ROW_SIZE + j].z)
				// 	glColor3ub(color_red(map.max_h, map.mp[i * ROW_SIZE + j].z), 128, 0);
				// else
				getNewCol(map.max_h, map.mp[i * ROW_SIZE + j].z, rgb);
				glColor3ub(rgb[0], rgb[1], rgb[2]);
				glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + j].z);


				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (0.0f + (float)(j) - ROW_SIZE/2);
				// if (map.mp[i * ROW_SIZE + j].z)
				// 	glColor3ub(color_red(map.max_h, map.mp[(i + 1) * ROW_SIZE + j].z), 191, 69);
				// else
				// 	glColor3ub(0, 255, 0);
				getNewCol(map.max_h, map.mp[(i + 1) * ROW_SIZE + j].z, rgb);
				glColor3ub(rgb[0], rgb[1], rgb[2]);
				glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + j].z);


				x = (1.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				// if (map.mp[i * ROW_SIZE + j].z)
				// 	glColor3ub(color_red(map.max_h, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z), 191, 69);
				// else
				// 	glColor3ub(0, 255, 0);
				getNewCol(map.max_h, map.mp[(i + 1) * ROW_SIZE + (j + 1)].z, rgb);
				glColor3ub(rgb[0], rgb[1], rgb[2]);
				glVertex3f(x, y, 0.0f + (float)map.mp[(i + 1) * ROW_SIZE + (j + 1)].z);

				x = (0.0f + (float)(i) - ROW_SIZE/2);
				y = (1.0f + (float)(j) - ROW_SIZE/2);
				// if (map.mp[i * ROW_SIZE + j].z)
				// 	glColor3ub(color_red(map.max_h, map.mp[i * ROW_SIZE + (j + 1)].z), 191, 69);
				// else
				// 	glColor3ub(0, 255, 0);
				getNewCol(map.max_h, map.mp[i * ROW_SIZE + (j + 1)].z, rgb);
				glColor3ub(rgb[0], rgb[1], rgb[2]);
				glVertex3f(x, y, 0.0f + (float)map.mp[i * ROW_SIZE + (j + 1)].z);

				glEnd();
				if (water == 1)
					water_pol(i, j, &map);
			}
		}

		wave_calc(map.mp);
		update_water(map.mp);
		SDL_GL_SwapWindow(win);
	}
	return (0);
}
