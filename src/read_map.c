/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:50:36 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 17:23:36 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_h.h"

void	del_str(char **line)
{
	if (line && *line)
		free(*line);
	*line = NULL;
}

void	del_tab(char ***tab)
{
	char	**p;
	int		i;

	i = -1;
	p = *tab;
	while (p[++i])
		free(p[i]);
	free(*tab);
	*tab = NULL;
}

void	init_coor(t_point *mp, char **tab, t_map *map)
{
	int		i;
	char	*line;
	char	**fl;
	int		cord;

	i = 0;
	while (tab[i])
	{
		line = tab[i];
		fl = ft_strsplit(line + 1, ',');
		(len_tab(fl) != 3) ? delete_mem(map, 1) : 0;
		cord = (ft_atoi(fl[0]) * ROW_SIZE / SIZE_M) +
			(ft_atoi(fl[1]) * ROW_SIZE / SIZE_M) * ROW_SIZE;
		mp[cord].z = (double)ft_atoi(fl[2]) * ROW_SIZE / SIZE_M;
		mp[cord].op = 1;
		(mp[cord].z > map->max_h) ? map->max_h = mp[cord].z : 0;
		psudo(mp, cord % ROW_SIZE, cord / ROW_SIZE);
		add_point(&(map->points), cord % ROW_SIZE, cord / ROW_SIZE, 1);
		del_tab(&fl);
		i++;
	}
}

void	read_map2(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		linecount;
	int		i;
	int		main_count;

	main_count = 0;
	linecount = -1;
	while (++linecount < ROW_SIZE && gnl(fd, &line))
	{
		if (line && *line)
		{
			i = -1;
			tab = ft_strsplit(line, ' ');
			while (tab[++i])
			{
				map->mp[main_count].z = atof(tab[i]);
				if (map->mp[main_count].z > map->max_h)
					map->max_h = map->mp[main_count].z;
				main_count++;
			}
			del_tab(&tab);
		}
		del_str(&line);
	}
}

void	read_map(int fd, t_map *map)
{
	char	*line;
	char	**tab;

	map->max_h = -1;
	if (map->rd == 0 || map->rd == 3)
	{
		line = NULL;
		while (gnl(fd, &line))
		{
			if (line && *line)
			{
				tab = ft_strsplit(line, ' ');
				init_coor(map->mp, tab, map);
				del_tab(&tab);
			}
			del_str(&line);
		}
	}
	else
		read_map2(fd, map);
	map->size_a = ROW_SIZE * 3;
	map->start = -1;
	map->flow = 0;
	map->rain_s = 7;
	map->rain_time = 0;
}
