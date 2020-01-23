#include "mod_h.h"

void	init_map(t_point *mp)
{
	int	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		mp[i].z = 0; // = 0
		mp[i].op = -1; //psudo opornya
		mp[i].x = 0;
		mp[i].y = 0;
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
			if (sqrt((pow(i - y, 2) + pow(j - x, 2))) < RADIUS && mp[i * 100 + j].op != 1)
				mp[i * 100 + j].op = 0;
			j++;
		}
		i++;
	}
}

void	init_coor(t_point	*mp, char **tab)
{
	int 	i;
	char	*line;
	char	**fl;

	int		x;
	int		y;
	int		z;

	i = 0;
	while (tab[i])
	{
		line = tab[i];
		fl = ft_strsplit(line + 1, ',');
		mp[(ft_atoi(fl[0]) / 2) + (ft_atoi(fl[1])/ 200)].z = ft_atoi(fl[2]) / 200;
		mp[(ft_atoi(fl[0]) / 2) + (ft_atoi(fl[1])/ 200)].op = 1;
		x = (ft_atoi(fl[0]) / 2) + (ft_atoi(fl[1])/ 200);
		psudo(mp, x % 100, x / 100);
		i++;
	}
}
void    read_map(int fd, t_map *map)
{
    char	*line;
	char	**tab;

	line = NULL;
	while (gnl(fd, &line))
	{
		if (line && *line)
		{
			tab = ft_strsplit(line, ' ');
			init_coor(map->mp, tab);
		}
		free(line);
	}
}