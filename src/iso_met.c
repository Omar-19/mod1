/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_met.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:38:14 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 15:00:02 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	add_point(t_listp **head, int x, int y, int type)
{
	t_listp *tmp;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = (t_listp *)malloc(sizeof(t_listp));
		(*head)->x = x;
		(*head)->y = y;
		(*head)->op = type;
		(*head)->next = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_listp *)malloc(sizeof(t_listp));
	tmp->next->x = x;
	tmp->next->y = y;
	tmp->next->op = type;
	tmp->next->next = NULL;
	return ;
}

void	init_map(t_point *mp)
{
	int	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		mp[i].z = 0;
		mp[i].op = -1;
		mp[i].x = i % ROW_SIZE;
		mp[i].y = i / ROW_SIZE;
		mp[i].wh = 0;
		mp[i].wh1 = 0;
		mp[i].h = 0;
		i++;
	}
}

void	null_border(t_map *map)
{
	int i;

	i = -1;
	while (++i < MAP_SIZE)
	{
		if (map->mp[i].x == 0 || map->mp[i].x == (ROW_SIZE - 1)
			|| map->mp[i].y == 0 || map->mp[i].y == (ROW_SIZE - 1))
		{
			map->mp[i].op = 1;
			add_point(&(map->points), map->mp[i].x, map->mp[i].y, -1);
		}
	}
	map->povyx = 0;
	map->povyx_d = 0;
	map->povz = 65;
	map->povz_d = 0;
	map->running = 1;
	map->water = 0;
}

void	psudo(t_point *mp, int x, int y)
{
	int		i;
	int		j;
	int		imax;
	int		jmax;

	i = (y - RADIUS < 0) ? 0 : y - RADIUS;
	jmax = (x + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : x + RADIUS;
	imax = (y + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : y + RADIUS;
	while (i < imax)
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j < jmax)
		{
			if (sqrt((pow(i - y, 2) + pow(j - x, 2))) < RADIUS
				&& mp[i * ROW_SIZE + j].op != 1)
				mp[i * ROW_SIZE + j].op = 0;
			j++;
		}
		i++;
	}
}
