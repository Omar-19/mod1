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
	float step = (float)(191 - 136) / (float)h_max;
	// ft_printf("col %d step %lf max h %d cur_h %d\n", 136 + (int)(h * step), step, h_max, h);
	return (136 + (int)(h * step));
}

void mov(float xpos, float zpos, float ypos, GLfloat yrot, GLfloat lookupdown)
{
	GLfloat x_m, y_m, z_m, u_m, v_m;

	GLfloat xtrans = -xpos;       // Проекция игрока на ось X
	GLfloat ztrans = -zpos;       // Проекция игрока на ось Z
	GLfloat ytrans = ypos;        // Проекция игрока на ось Y

	// 360 градусный угол для поворота игрока
	GLfloat sceneroty = 360.0f - yrot;
	int numtriangles;           // Количество треугольников
	// Вращать в соответствии с направлением взгляда игрока по вертикали
	glRotatef(lookupdown,1.0f,0,0);
	glRotatef(sceneroty,0,1.0f,0);//по горизонтали

	// Проецировать сцену относительно игрока
	glTranslatef(xtrans, ytrans, ztrans);

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
	null_border(&map);
	int i = 0;
	// ft_printf("%2.0f ", (float)1);
	// exit(0);
	altitude_calculation(&map);
	// up_water(map.mp);
	// 	// add_rain(&map);
	// i = 0;
	// while (i < MAP_SIZE)
	// {
	// 	ft_printf("%2d ", (int)map.mp[i].wh);
	// 	if ((i + 1) % ROW_SIZE == 0)
	// 		write(1, "\n", 1);
	// 	i++;
	// }
	// write(1, "\n", 1);
	// write(1, "water\n", 6);

	// while (i < MAP_SIZE)
	// {
	// 	ft_printf("%2d ", map.mp[i].z);
	// 	if ((i + 1) % ROW_SIZE == 0)
	// 		write(1, "\n", 1);
	// 	i++;
	// }
	initGLandSDL(); //#tut
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
	int povx = -70;
	int povy = -70;
	int povz = -70;
	// glRotatef(pov, 1, 0, 0);
	int l = 0;

	gluLookAt(60.0, 60.0, 20.5, 0.0, 0.0, 0.0, -1.0, -1.0, 1.0);
	// glTranslatef(0, 0, 50);

	while (running) //running
	{

		while ( SDL_PollEvent(&event) )
		{
			switch (event.type)
			{
				case SDL_QUIT:
					running = 0;
					break;
				case SDL_MOUSEBUTTONDOWN:
					// printf("mouse x = %d , y = %d\n", event.button.x, event.button.y);
					break;
				case SDL_MOUSEBUTTONUP:
					// printf("mouse x = %d , y = %d, dx = %d, dy = %d\n", event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
					// if (event.motion.y != oldy)
					// {
					// 	lookupdown -= (oldy - event.motion.y) / sensitivity;
					// }
					// if (event.motion.x != oldx)
					// {
					// 	heading -= (oldx - event.motion.x) / sensitivity;
					// 	yrot = heading;
					// }
					// oldx = event.motion.x;
					// oldy = event.motion.y;
					// mov(xpos, zpos, ypos, yrot, lookupdown);
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_s )     // Клавиша стрелка вверх нажата?
					{
						// // Переместиться по оси X вектора направления игрока
						// xpos -= (float)sin(heading*piover180) * 0.05f;
						// // Переместиться по оси Z вектора направления игрока
						// zpos -= (float)cos(heading*piover180) * 0.05f;
						// ypos -= (float)sin(lookupdown*piover180) * 0.05f;
						povx += 10;
						glRotatef(povx, 1, 0, 0);
					}
					if (event.key.keysym.sym == SDLK_w)   // Клавиша стрелка вниз нажата?
					{
						// Переместиться по оси X вектора направления игрока
						// xpos += (float)sin(heading*piover180) * 0.05f;
						// // Переместиться по оси Z вектора направления игрока
						// zpos += (float)cos(heading*piover180) * 0.05f;
						// ypos += (float)sin(lookupdown*piover180) * 0.05f;
						povy += 10;
						glRotatef(povy, 0, 1, 0);
					}
					if (event.key.keysym.sym == SDLK_a)
					{
						// xpos += (float)sin((heading-90)*piover180) * 0.05f;
						// zpos += (float)cos((heading-90)*piover180) * 0.05f;
						// ypos += (float)sin(lookupdown*piover180) * 0.05f;
						povz += 10;
						glRotatef(povz, 0, 0, 1);
					}
					if (event.key.keysym.sym == SDLK_d)
					{
						// xpos -= (float)sin((heading-90)*piover180) * 0.05f;
						// zpos -= (float)cos((heading-90)*piover180) * 0.05f;
					}
					// mov(xpos, zpos, ypos, yrot, lookupdown);
					break;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

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
			}
			i += 1;
		}
		// glTranslatef(0, --l, 0);
		// usleep(300000);
		// up_water(map.mp);
		// // add_rain(&map);
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
		// break;
		// wave_calc(map.mp);
		// update_water(map.mp);
		// running = 0;
		// glRotatef(45, 0, 1, 0);
		// usleep(300000);
		glEnd();
		SDL_GL_SwapWindow(win);
	} //tuutt
	return (0);
}
