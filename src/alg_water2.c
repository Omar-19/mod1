/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_water2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:03:03 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 16:09:48 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	add_wave(t_map *map)
{
	int	i;

	i = map->start;
	while (++i < map->size_a)
	{
		if (map->ar == 1 || map->ar == 4)
			map->mp[i].wh += 500;
		else if (map->ar == 2 && i % ROW_SIZE == 0)
			map->mp[i].wh += 500;
		else if (map->ar == 3 && i % ROW_SIZE == ROW_SIZE - 1)
			map->mp[i].wh += 500;
	}
}

void	add_rain(t_map *map)
{
	int secret;

	secret = rand() % MAP_SIZE + 1;
	map->rain_time++;
	if (map->rain_time < 10)
		return ;
	map->rain_time = 0;
	map->mp[secret].wh += 0.1;
}

void	water_f(int key, t_map *map)
{
	if (key == 0 || key == 1)
		up_water(map->mp, key);
	else if (key == 2)
		add_wave(map);
}

void	earn_c(int i, int j, t_map *map, double *rgb)
{
	float x;
	float y;

	glBegin(GL_POLYGON);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	getnewcol(map->max_h, map->mp[i * ROW_SIZE + j].z, rgb);
	glColor3ub(rgb[0], rgb[1], rgb[2]);
	glVertex3f(x, y, map->mp[i * ROW_SIZE + j].z);
	x = (1.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	getnewcol(map->max_h, map->mp[(i + 1) * ROW_SIZE + j].z, rgb);
	glColor3ub(rgb[0], rgb[1], rgb[2]);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].z);
	x = (1.0f + i - (float)ROW_SIZE / 2);
	y = (1.0f + j - (float)ROW_SIZE / 2);
	getnewcol(map->max_h, map->mp[(i + 1) * ROW_SIZE + (j + 1)].z, rgb);
	glColor3ub(rgb[0], rgb[1], rgb[2]);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (1.0f + j - (float)ROW_SIZE / 2);
	getnewcol(map->max_h, map->mp[i * ROW_SIZE + (j + 1)].z, rgb);
	glColor3ub(rgb[0], rgb[1], rgb[2]);
	glVertex3f(x, y, map->mp[i * ROW_SIZE + (j + 1)].z);
	glEnd();
}
