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
	// jmax = (x + RADIUS > ROW_SIZE) ? ROW_SIZE : x + RADIUS;
	// imax = (y + RADIUS > ROW_SIZE) ? ROW_SIZE : y + RADIUS;
	while (i <= imax) //(i < imax) +++
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j <= jmax) //(j < jmax) +++
		{
			// if (map->mp[i * 100 + j].op && sqrt((pow(i - x, 2) + pow(j - y, 2))) <= RADIUS)
			if (map->mp[i * 100 + j].op && sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
				z += (map->mp[i * 100 + j].d_io / sum_d) * map->mp[i * 100 + j].z;
			j++;
		}
		i++;
	}
	map->mp[x * 100 + y].z = z;
	// printf("   z = %d = %f\n", (int)(z), z);
}

void    altitude(t_map *map, int x, int y)
{
    double	sum_d;
	
	int n_s_d;

    int		i;
	int		j;
	int		imax;
	int		jmax;

	n_s_d = 0;
	sum_d = 0;
	// i = (y - RADIUS < 0) ? 0 : y - RADIUS;
	// j = (x - RADIUS < 0) ? 0 : x - RADIUS;
	// jmax = (x + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : x + RADIUS;
	// imax = (y + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : y + RADIUS;
	i = (y - RADIUS < 0) ? 0 : y - RADIUS;
	j = (x - RADIUS < 0) ? 0 : x - RADIUS;
	jmax = (x + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : x + RADIUS;
	imax = (y + RADIUS > ROW_SIZE - 1) ? ROW_SIZE - 1 : y + RADIUS;
	// jmax = (x + RADIUS > ROW_SIZE) ? ROW_SIZE : x + RADIUS;
	// imax = (y + RADIUS > ROW_SIZE) ? ROW_SIZE : y + RADIUS;
	// ft_printf("from %d to %d\n", i, imax);
	// ft_printf("FOR(%d, %d) Y: from %d to %d ------- ", x, y, i, imax);
	// ft_printf("X: from %d to %d\n", j, jmax);
	while (i <= imax) //(i < imax) +++
	{
		j = (x - RADIUS < 0) ? 0 : x - RADIUS;
		while (j <= jmax)//(j < jmax) +++
		{
			// if (map->mp[i * 100 + j].op && sqrt((pow(i - x, 2) + pow(j - y, 2))) <= RADIUS) +++
			// ft_printf("len = %lf  (%d, %d)\n", sqrt((pow(abs(i - x), 2) + pow(abs(j - y), 2))), j, i);
			if (map->mp[i * 100 + j].op && sqrt((pow(abs(i - y), 2) + pow(abs(j - x), 2))) < RADIUS)
			{
				map->mp[i * 100 + j].d_io = pow(sqrt((pow(i - y, 2) + pow(j - x, 2))), (-1) * POWER);
				sum_d += map->mp[i * 100 + j].d_io;
				++n_s_d;
			}
			j++;
		}
		i++;
	}
	// ft_printf("num sum_d = %d\n\n", n_s_d);
	alpha(map, x, y, sum_d);
}


void	altitude_calculation(t_map *map)
{
	int		i;
	double	dio;
	double	l_i;

	i = -1;
	while(++i < MAP_SIZE)
	{
		if (map->mp[i].op)
			continue;
		altitude(map, map->mp[i].x, map->mp[i].y);
	}
}