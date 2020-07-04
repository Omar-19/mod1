/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_watet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:04:14 by btheia            #+#    #+#             */
/*   Updated: 2020/07/03 11:38:26 by btheia           ###   ########.fr       */
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

float	check_w(t_point *mp, int i, int j, float n, int *num)
{
	float	sum;

	sum = -1;
	if (i - 1 >= 0)//&& n > mp[(i - 1) * 100 + j].z + mp[(i - 1) * 100 + j].wh)
	{
		if (mp[(i - 1) * ROW_SIZE + j].z > n && !mp[(i - 1) * ROW_SIZE + j].wh)
		{

		}
		else
		{
			(*num)++;
			sum += mp[(i - 1) * ROW_SIZE + j].z + mp[(i - 1) * ROW_SIZE + j].wh;
		}
	}
	if (i + 1 < ROW_SIZE)//&& n > mp[(i + 1) * 100 + j].z + mp[(i + 1) * 100 + j].wh)
	{
		if (mp[(i + 1) * ROW_SIZE + j].z > n && !mp[(i + 1) * ROW_SIZE + j].wh)
		{

		}
		else
		{
			(*num)++;
			sum += mp[(i + 1) * ROW_SIZE + j].z + mp[(i + 1) * ROW_SIZE + j].wh;
		}
	}

	if (j + 1 < ROW_SIZE)// && n > mp[i * 100 + j + 1].z + mp[i * 100 + j + 1].wh)
	{
		if ( mp[i * ROW_SIZE + j + 1].z > n && !mp[i * ROW_SIZE + j + 1].wh)
		{

		}
		else
		{
			(*num)++;
			sum += mp[i * ROW_SIZE + j + 1].z + mp[i * ROW_SIZE + j + 1].wh;
		}
	}
	if (j - 1 >= 0)// && n > mp[i * 100 + j - 1].z + mp[i * 100 + j - 1].wh)
	{
		if (mp[i * ROW_SIZE + j - 1].z > n && !mp[i * ROW_SIZE + j - 1].wh)
		{

		}
		else
		{
			(*num)++;
			sum += mp[i * ROW_SIZE + j - 1].z + mp[i * ROW_SIZE + j - 1].wh;
		}
	}
	return (sum == -1.0) ? -1.0 : ++sum;
}

void	wave_calc(t_point *mp)
{
	int			i;
	float		sum;
	float		h1;
	int num;

	i = -1;
	while (++i < MAP_SIZE)
	{
		h1 = 0;
		num = 0;
		sum = check_w(mp, i / ROW_SIZE, i % ROW_SIZE, mp[i].wh + mp[i].z, &num);
		if (sum >= 0)
		{
			h1 = (mp[i].wh + mp[i].z) - (num * (mp[i].wh + mp[i].z) - sum) / num;
			if (h1 >= mp[i].z)
				mp[i].wh1 = h1 - mp[i].z;
			else
				mp[i].wh1 = 0;
		}
		else
			mp[i].wh1 = mp[i].wh;
	}
}
