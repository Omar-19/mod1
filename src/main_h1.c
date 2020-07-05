/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_h1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:04:10 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 16:52:37 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mod_h.h"

int		h_bool(int i, int j, t_map *map)
{
	return (map->mp[i * ROW_SIZE + j].wh +
		map->mp[i * ROW_SIZE + j].z > map->mp[i * ROW_SIZE + j].z);
}

void	water_pol_h(int i, int j, t_map *map)
{
	float x;
	float y;

	x = (1.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	if (h_bool(i + 1, j + 1, map))
		glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + (j + 1)].wh
		+ map->mp[(i + 1) * ROW_SIZE + (j + 1)].z);
	x = (0.0f + i - ROW_SIZE / 2);
	y = (1.0f + j - ROW_SIZE / 2);
	if (h_bool(i, j + 1, map))
		glVertex3f(x, y, map->mp[i * ROW_SIZE + (j + 1)].wh
		+ map->mp[i * ROW_SIZE + (j + 1)].z);
}

void	water_pol(int i, int j, t_map *map)
{
	float x;
	float y;

	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);
	x = (0.0f + i - ROW_SIZE / 2);
	y = (0.0f + j - ROW_SIZE / 2);
	if (h_bool(i, j, map))
		glVertex3f(x, y, map->mp[i * ROW_SIZE + j].wh +
		map->mp[i * ROW_SIZE + j].z);
	x = (1.0f + i - ROW_SIZE / 2);
	y = (0.0f + j - ROW_SIZE / 2);
	if (h_bool(i + 1, j, map))
		glVertex3f(x, y, map->mp[(i + 1) * ROW_SIZE + j].wh
		+ map->mp[(i + 1) * ROW_SIZE + j].z);
	water_pol_h(i, j, map);
	glEnd();
	water_pol2(i, j, map);
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

void	save_file(t_map *map)
{
	int	i;
	int	fd_out;

	i = 0;
	fd_out = open("map.mods", O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD);
	if (fd_out == -1)
	{
		ft_printf("Cannot save map!\n");
		exit(0);
	}
	while (i < MAP_SIZE)
	{
		dprintf(fd_out, "%2.2lf ", map->mp[i].z);
		if ((i + 1) % ROW_SIZE == 0)
			dprintf(fd_out, "\n");
		i++;
	}
}
