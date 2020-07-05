/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude_calculation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:36:02 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 14:48:38 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	alpha(t_map *map, int x, int y, double sum_d)
{
	double	z;
	int		i;
	int		j;
	int		imax;
	int		jmax;

	z = 0;
	i = (y - RADIUS < 0) ? 0 : y - (RADIUS - 1);
	jmax = (x + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : x + RADIUS;
	imax = (y + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : y + RADIUS;
	while (i <= imax)
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j <= jmax)
		{
			if (map->mp[i * ROW_SIZE + j].op &&
				sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
				z += (map->mp[i * ROW_SIZE + j].d_io / sum_d) *
					map->mp[i * ROW_SIZE + j].z;
			j++;
		}
		i++;
	}
	map->mp[x * ROW_SIZE + y].z = z;
}

double	a2h(t_map *map, int i, int j, int key)
{
	double	kof;

	kof = 1;
	if (key == -1)
		kof = 0.005;
	return (kof * map->mp[i * ROW_SIZE + j].d_io);
}

void	altitude2(t_map *map, int x, int y)
{
	double	sum_d;
	double	sum_z_d;
	t_listp	*tmp;
	int		i;
	int		j;

	tmp = map->points;
	sum_d = 0;
	sum_z_d = 0;
	while (tmp)
	{
		i = tmp->y;
		j = tmp->x;
		if (sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
		{
			map->mp[i * ROW_SIZE + j].d_io = pow(sqrt((pow(i - y, 2) +
				pow(j - x, 2))), (-1) * POWER);
			sum_d += a2h(map, i, j, tmp->op);
			sum_z_d += map->mp[i * ROW_SIZE + j].z * a2h(map, i, j, tmp->op);
		}
		tmp = tmp->next;
	}
	map->mp[x * ROW_SIZE + y].z = sum_z_d / sum_d;
}

void	altitude_calculation(t_map *map)
{
	int		i;
	int		l;
	int		k;

	k = 0;
	l = 0;
	i = -1;
	while (++i < MAP_SIZE)
	{
		if (map->mp[i].op || map->mp[i].h)
		{
			k++;
			continue;
		}
		l++;
		map->mp[i].h = 1;
		altitude2(map, map->mp[i].x, map->mp[i].y);
	}
}
