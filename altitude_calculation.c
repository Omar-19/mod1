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
	while (i <= imax) //(i < imax) +++
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j <= jmax) //(j < jmax) +++
		{
			if (map->mp[i * ROW_SIZE + j].op && sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
				z += (map->mp[i * ROW_SIZE + j].d_io / sum_d) * map->mp[i * ROW_SIZE + j].z;
			j++;
		}
		i++;
	}
	map->mp[x * ROW_SIZE + y].z = z;
}

void	altitude(t_map *map, int x, int y)
{
	double	sum_d;
	double	sum_z_d;

	int		i;
	int		j;
	int		imax;
	int		jmax;


	sum_d = 0;
	sum_z_d = 0;
	i = (y - RADIUS < 0) ? 0 : y - RADIUS;
	j = (x - RADIUS < 0) ? 0 : x - RADIUS;
	jmax = (x + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : x + RADIUS;
	imax = (y + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : y + RADIUS;
	while (i <= imax) //(i < imax) +++
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j <= jmax)//(j < jmax) +++
		{
			if (map->mp[i * ROW_SIZE + j].op && sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
			{
				map->mp[i * ROW_SIZE + j].d_io = pow(sqrt((pow(i - y, 2) + pow(j - x, 2))), (-1) * POWER);
				sum_d += map->mp[i * ROW_SIZE + j].d_io;
				sum_z_d += map->mp[i * ROW_SIZE + j].z * map->mp[i * ROW_SIZE + j].d_io;
			}
			j++;
		}
		i++;
	}
	map->mp[x * ROW_SIZE + y].z = sum_z_d / sum_d;
}

void	altitude2(t_map *map, int x, int y)
{
	double	sum_d;
	double	sum_z_d;
	t_listp	*tmp;
	int		i;
	int		j;

	int test = 0;
	tmp = map->points;
	sum_d = 0;
	sum_z_d = 0;
	while (tmp) //(i < imax) +++
	{
		i = tmp->y;
		j = tmp->x;
		if (sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
		{
			map->mp[i * ROW_SIZE + j].d_io = pow(sqrt((pow(i - y, 2) + pow(j - x, 2))), (-1) * POWER);
			sum_d += map->mp[i * ROW_SIZE + j].d_io;
			sum_z_d += map->mp[i * ROW_SIZE + j].z * map->mp[i * ROW_SIZE + j].d_io;
		}
		tmp = tmp->next;
	}
	map->mp[x * ROW_SIZE + y].z = sum_z_d / sum_d;
}

void	altitude_calculation(t_map *map)
{
	int		i;
	double	dio;
	double	l_i;
	int		l;
	int		k;

	k = 0;
	l = 0;
	i = -1;
	while(++i < MAP_SIZE)
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
	ft_printf("l = %d k = %d sum %d\n", l, k, l + k);
}
