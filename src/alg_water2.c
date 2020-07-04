/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_water2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:03:03 by btheia            #+#    #+#             */
/*   Updated: 2020/07/03 11:36:51 by btheia           ###   ########.fr       */
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
	int	i;

	i = -1;
	while (++i < MAP_SIZE)
	{
		if (i % map->rain_s)
			map->mp[i].wh += 0.05;
	}
}
