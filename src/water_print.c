/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:21:14 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 15:24:44 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mod_h.h"

void	water_right(int i, int j, t_map *map)
{
	float x;
	float y;

	x = (0.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[i * ROW_SIZE + (j + 1)].wh +
		(float)map->mp[i * ROW_SIZE + (j + 1)].z);
	x = (0.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[i * ROW_SIZE + (j + 1)].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh +
		(float)map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
}

void	water_front(int i, int j, t_map *map)
{
	float x;
	float y;

	x = (1.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh +
		map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (0.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (0.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].wh +
		map->mp[(i + 1) * ROW_SIZE + j].z);
}

void	water_left(int i, int j, t_map *map)
{
	float x;
	float y;

	x = (1.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].wh +
		map->mp[(i + 1) * ROW_SIZE + j].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (0.0f + j - ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[i * ROW_SIZE + j].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[i * ROW_SIZE + j].wh +
		map->mp[i * ROW_SIZE + j].z);
}

void	water_back(int i, int j, t_map *map)
{
	float x;
	float y;

	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[i * ROW_SIZE + j].wh +
		map->mp[i * ROW_SIZE + j].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (0.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[i * ROW_SIZE + j].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (1.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, (float)map->mp[i * ROW_SIZE + (j + 1)].z);
	x = (0.0f + i - (float)ROW_SIZE / 2);
	y = (1.0f + j - (float)ROW_SIZE / 2);
	glVertex3f(x, y, map->mp[i * ROW_SIZE + (j + 1)].wh +
		map->mp[i * ROW_SIZE + (j + 1)].z);
}

void	water_pol2(int i, int j, t_map *map)
{
	if (i == 0 || i == ROW_SIZE - 2 || j == 0 || j == ROW_SIZE - 2)
	{
		glBegin(GL_POLYGON);
		water_right(i, j, map);
		water_front(i, j, map);
		water_left(i, j, map);
		water_back(i, j, map);
		glEnd();
	}
}
