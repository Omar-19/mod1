/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_h2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:06:22 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 17:24:38 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mod_h.h"

void	getnewcol3(double proc, double *rgb)
{
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

void	getnewcol2(double proc, double *rgb)
{
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
	getnewcol3(proc, rgb);
}

void	getnewcol(double max, double z, double *rgb)
{
	double proc;

	proc = z / max;
	if (z == 0)
	{
		rgb[0] = 0;
		rgb[1] = 255;
		rgb[2] = 0;
		return ;
	}
	if (proc <= 0.08)
	{
		rgb[0] = 10;
		rgb[1] = 230;
		rgb[2] = 0;
	}
	if (0.08 < proc && proc <= 0.31)
	{
		rgb[0] = 0;
		rgb[1] = 204;
		rgb[2] = 0;
	}
	getnewcol2(proc, rgb);
}

void	delete_mem(t_map *map, int key)
{
	t_listp *tmp;
	t_listp *next;

	(map->rd == 3 && !key) ? save_file(map) : 0;
	if (map->mp)
		free(map->mp);
	if (map->points)
	{
		tmp = map->points;
		while (tmp->next)
		{
			next = tmp->next;
			free(tmp);
			tmp = NULL;
			tmp = next;
		}
		free(tmp);
	}
	map->mp = NULL;
	map->points = NULL;
	endsdl();
	if (key)
		exit(0);
}

void	keyb2(SDL_Event event, t_map *map)
{
	if (event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_q)
		map->water = (event.key.keysym.sym == SDLK_e) ? 1 : 0;
	if (event.key.keysym.sym == SDLK_h || event.key.keysym.sym == SDLK_l)
	{
		map->flow = (event.key.keysym.sym == SDLK_h) ? 0 : 1;
		water_f(map->flow, map);
	}
	if (event.key.keysym.sym == SDLK_u)
		water_f(2, map);
	if (event.key.keysym.sym == SDLK_r)
		map->flow = (map->flow == 4) ? 0 : 4;
	if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_2
		|| event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_4)
		rain_info(map, event.key.keysym.sym);
}
