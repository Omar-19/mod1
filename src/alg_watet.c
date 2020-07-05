/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_watet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:04:14 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 16:12:46 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	up_water(t_point *mp, int key)
{
	int		i;
	double	fl;

	i = -1;
	fl = (key == 0) ? 0.9 : -0.9;
	while (++i < MAP_SIZE)
	{
		if (mp[i].z == 0 && !key)
			mp[i].wh += fl;
		if (key)
			mp[i].wh += (mp[i].wh >= 0) ? fl : 0;
		if (mp[i].wh <= 0)
			mp[i].wh = 0;
	}
}

void	update_water(t_point *mp)
{
	int	i;

	i = -1;
	while (++i < MAP_SIZE)
	{
		if (mp[i].wh1 >= 0)
			mp[i].wh = mp[i].wh1;
		mp[i].wh1 = 0;
	}
}

float	check_wh(t_point *mp, int i, int j, int *num)
{
	(*num)++;
	return (mp[i * ROW_SIZE + j].z + mp[i * ROW_SIZE + j].wh);
}

float	check_w(t_point *mp, int *a, float n, int *num)
{
	float	sum;
	int		i;
	int		j;

	i = a[0];
	j = a[1];
	sum = -1;
	if (i - 1 >= 0 && (!(mp[(i - 1) * ROW_SIZE + j].z > n)
		|| (mp[(i - 1) * ROW_SIZE + j].wh)))
		sum += check_wh(mp, i - 1, j, num);
	if (i + 1 < ROW_SIZE && (!(mp[(i + 1) * ROW_SIZE + j].z > n)
		|| mp[(i + 1) * ROW_SIZE + j].wh))
		sum += check_wh(mp, i + 1, j, num);
	if (j + 1 < ROW_SIZE && (!(mp[i * ROW_SIZE + j + 1].z > n)
		|| mp[i * ROW_SIZE + j + 1].wh))
		sum += check_wh(mp, i, j + 1, num);
	if (j - 1 >= 0 && (!(mp[i * ROW_SIZE + j - 1].z > n)
		|| mp[i * ROW_SIZE + j - 1].wh))
		sum += check_wh(mp, i, j - 1, num);
	return (sum == -1.0) ? -1.0 : ++sum;
}

void	wave_calc(t_point *mp, t_map *map, int i)
{
	float		sum;
	float		h1;
	int			num[3];

	i = -1;
	while (++i < MAP_SIZE)
	{
		h1 = 0;
		num[2] = 0;
		num[0] = i / ROW_SIZE;
		num[1] = i % ROW_SIZE;
		sum = check_w(mp, num, mp[i].wh + mp[i].z, &num[2]);
		if (sum >= 0)
		{
			h1 = (mp[i].wh + mp[i].z) -
				(num[2] * (mp[i].wh + mp[i].z) - sum) / num[2];
			if (h1 >= mp[i].z)
				mp[i].wh1 = h1 - mp[i].z;
			else
				mp[i].wh1 = 0;
		}
		else
			mp[i].wh1 = mp[i].wh;
	}
	update_water(map->mp);
}
