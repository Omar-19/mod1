/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:04:22 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 17:15:25 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mod_h.h"

SDL_Window *g_win = NULL;

void	initglandsdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to init SDL, error.\n");
		exit(1);
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	g_win = SDL_CreateWindow("Mod1",
							SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							1000, 1000,
							SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(g_win);
	if (g_win == NULL)
		exit(1);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(5.0);
	glDepthFunc(GL_LESS);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(0.002 * 2, 0.002 * 2, 0.002 * 2);
	gluLookAt(60.0, 60.0, 30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	glRotatef(65, 0, 0, 1);
}

void	endsdl(void)
{
	SDL_DestroyWindow(g_win);
	SDL_Quit();
}

void	keyb(SDL_Event event, t_map *map)
{
	if (event.type == SDL_QUIT)
		map->running = 0;
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_w)
		{
			map->povyx_d = (event.key.keysym.sym == SDLK_w) ? -2.0 : 2.0;
			map->povyx += map->povyx_d;
			if (map->povyx < 4 && map->povyx >= -30)
				glRotatef(map->povyx_d, 1, -1, 0);
		}
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)
		{
			map->povz_d = (event.key.keysym.sym == SDLK_a) ? 2.0 : -2.0;
			map->povz += map->povz_d;
			if (map->povz < 133 && map->povz >= -45)
				glRotatef(map->povz_d, 0, 0, 1);
		}
		keyb2(event, map);
	}
}

void	main_loop(t_map *map)
{
	double		rgb[3];
	SDL_Event	event;
	int			i;
	int			j;

	while (map->running)
	{
		while (SDL_PollEvent(&event))
			keyb(event, map);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		(map->flow == 4) ? add_rain(map) : 0;
		i = -1;
		while (++i < ROW_SIZE - 1)
		{
			j = -1;
			while (++j < ROW_SIZE - 1)
			{
				earn_c(i, j, map, rgb);
				(map->water == 1) ? water_pol(i, j, map) : 0;
			}
		}
		wave_calc(map->mp, map, -1);
		SDL_GL_SwapWindow(g_win);
	}
}

int		main(int ac, char **av)
{
	t_map map;

	if (ac < 2)
	{
		ft_printf("Usage: mod1 [map file] [-key]:\nnone - full start \
		\n-f read map from file\n-s save map in \'map.mods\'\n");
		exit(0);
	}
	(ac == 2) ? map.rd = 0 : 0;
	(ac == 3 && !ft_strcmp("-f", av[2])) ? map.rd = 1 : 0;
	(ac == 3 && !ft_strcmp("-s", av[2])) ? map.rd = 3 : 0;
	if ((map.fd = open(av[1], O_RDONLY)) == -1)
		exit(0);
	if ((map.mp = (t_point *)malloc(sizeof(t_point) * MAP_SIZE)) == NULL)
		exit(0);
	map.points = NULL;
	map.ar = 1;
	init_map(map.mp);
	read_map(map.fd, &map);
	null_border(&map);
	(map.rd == 0 || map.rd == 3) ? altitude_calculation(&map) : 0;
	initglandsdl();
	main_loop(&map);
	delete_mem(&map, 0);
	return (0);
}
