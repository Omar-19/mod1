#include "mod_h.h"

void	add_point(t_listp **head, int x, int y)
{
	t_listp *tmp;

	if (head == NULL)
		return;
	if (*head == NULL)
	{
		*head = (t_listp *)malloc(sizeof(t_listp));
		(*head)->x = x;
		(*head)->y = y;
		(*head)->next = NULL;
		return;
	}
	tmp = *head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = (t_listp *)malloc(sizeof(t_listp));
	tmp->next->x = x;
	tmp->next->y = y;
	tmp->next->next = NULL;
	return;
}

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
		mp[i].h = 0;
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
	{
		if (map->mp[i].x == 0 || map->mp[i].x == (ROW_SIZE - 1) || map->mp[i].y == 0 || map->mp[i].y == (ROW_SIZE - 1))
		{
			map->mp[i].op = 1;
			add_point(&(map->points), map->mp[i].x, map->mp[i].y);
		}
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
		psudo(mp, cord % ROW_SIZE, cord / ROW_SIZE);
		add_point(&(map->points), cord % ROW_SIZE, cord / ROW_SIZE);
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
