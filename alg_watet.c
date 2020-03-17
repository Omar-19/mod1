/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_watet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:04:14 by btheia            #+#    #+#             */
/*   Updated: 2020/03/17 16:16:30 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	up_water(t_point *mp)
{
    int i;

    i = -1;
    while (++i < MAP_SIZE)
    {
        if (mp[i].z == 0)
            mp[i].wh += (float)1;
    }
}

void	update_water(t_point *mp)
{
    int i;

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
	// if (i - 1 >= 0 && mp[(i - 1) * ROW_SIZE + j].wh )//&& n > mp[(i - 1) * 100 + j].z + mp[(i - 1) * 100 + j].wh)
	// {
	// 	(*num)++;
	// 	sum += mp[(i - 1) * ROW_SIZE + j].z + mp[(i - 1) * ROW_SIZE + j].wh;
	// }
	// if (i + 1 < ROW_SIZE && mp[(i + 1) * ROW_SIZE + j].wh )//&& n > mp[(i + 1) * 100 + j].z + mp[(i + 1) * 100 + j].wh)
	// {
	// 	(*num)++;
	// 	sum += mp[(i + 1) * ROW_SIZE + j].z + mp[(i + 1) * ROW_SIZE + j].wh;
	// }

	// if (j + 1 < ROW_SIZE && mp[i * ROW_SIZE + j + 1].wh)// && n > mp[i * 100 + j + 1].z + mp[i * 100 + j + 1].wh)
	// {
	// 	(*num)++;
	// 	sum += mp[i * ROW_SIZE + j + 1].z + mp[i * ROW_SIZE + j + 1].wh;
	// }
	// if (j - 1 >= 0 && mp[i * ROW_SIZE + j - 1].wh)// && n > mp[i * 100 + j - 1].z + mp[i * 100 + j - 1].wh)
	// {
	// 	(*num)++;
	// 	sum += mp[i * ROW_SIZE + j - 1].z + mp[i * ROW_SIZE + j - 1].wh;
	// }
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
			// ft_printf("i %d j = %d %lf\n", i / 100, i % 100, h1);
			// if (i == 0)
			// 	ft_printf("i %d j = %d sum %lf h1 %lf z %d \n", i / 100, i % 100, sum, h1, mp[i].z);
			if (h1 >= mp[i].z)
				mp[i].wh1 = h1 - mp[i].z;
			else
				mp[i].wh1 = 0;
		}
		else
			mp[i].wh1 = mp[i].wh;
    }
}
