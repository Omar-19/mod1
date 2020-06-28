#include "mod_h.h"

void	init_map(t_point *mp)
{
	int	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		mp[i].z = 0;
		mp[i].op = -1;//-1;// ++++++++++++++++
		mp[i].x = i % ROW_SIZE;
		mp[i].y = i / ROW_SIZE;
		mp[i].wh = 0;
		mp[i].wh1 = 0;
		i++;
	}
}

void	init_x_y(t_map *map)
{
	int i;

	i = -1;
	while (++i < MAP_SIZE)
	{
		map->mp[i].y = i / ROW_SIZE;
		map->mp[i].x = i % ROW_SIZE;
	}
}

void	null_border(t_map *map)
{
	int i = -1;

	while (++i < MAP_SIZE)
		if (map->mp[i].x == 0 || map->mp[i].x == (ROW_SIZE - 1) || map->mp[i].y == 0 || map->mp[i].y == (ROW_SIZE - 1))
			map->mp[i].op = 1;
}

void	psudo(t_point	*mp, int x, int y)
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
			if (sqrt((pow(i - y, 2) + pow(j - x, 2))) < RADIUS && mp[i * ROW_SIZE + j].op != 1)
				mp[i * ROW_SIZE + j].op = 0;
			j++;
		}
		i++;
	}
}

void	init_coor(t_point	*mp, char **tab, t_map *map)
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
		cord = (ft_atoi(fl[0]) * ROW_SIZE / SIZE_M) + (ft_atoi(fl[1]) * ROW_SIZE / SIZE_M) * ROW_SIZE;
		mp[cord].z = ft_atoi(fl[2]) * ROW_SIZE / SIZE_M;
		mp[cord].op = 1;
		if (mp[cord].z > map->max_h)
			map->max_h = mp[cord].z;
		// mp[(ROW_SIZE / 2) * ROW_SIZE + ROW_SIZE / 2].z = 3000;
		// mp[(ROW_SIZE / 2) * ROW_SIZE + ROW_SIZE / 2].op = 1;
		// x = (ROW_SIZE / 2) * ROW_SIZE + ROW_SIZE / 2;
		psudo(mp, cord % ROW_SIZE, cord / ROW_SIZE);
		i++;
	}

}

void	read_map(int fd, t_map *map)
{
	char	*line;
	char	**tab;

	line = NULL;
	map->max_h = -1;
	while (gnl(fd, &line))
	{
		if (line && *line)
		{
			tab = ft_strsplit(line, ' ');
			init_coor(map->mp, tab, map);
		}
		free(line);
	}
}
