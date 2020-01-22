#include "header.h"

double sum_dio(t_map *map, int i)
{
	int	j;
	int	row;

	// j = 0;
	// row = i / ROW_SIZE * ROW_SIZE - ((i % ROW_SIZE < RADIUS))
	// while (j <= (int)(RADIUS * 2))
	// {
	// 	// row = ROW_SIZE * j;

	// }
}

void	altitude_calculation(t_map *map)
{
	int		i;
	double	sum_d;
	double	dio;
	double	l_i;

	i = -1;
	while(++i < MAP_SIZE)
	{
		if (map->mp[0].op)
			continue;
		sum_d = sum_dio(map, i);
		
	}
}

int main()
{
	t_map map;

	map.mp[0].z = 3;
	map.mp[0].op = 1;

	map.mp[1].z = 3;
	map.mp[1].op = 1;

	map.mp[2].z = 3;
	map.mp[2].op = 1;

	map.mp[3].z = 2;
	map.mp[3].op = 1;

	map.mp[4].z = 0;
	map.mp[4].op = 0;

	map.mp[5].z = 2;
	map.mp[5].op = 1;

	map.mp[6].z = 1;
	map.mp[6].op = 1;

	map.mp[7].z = 1;
	map.mp[7].op = 1;

	map.mp[8].z = 1;
	map.mp[8].op = 1;

	altitude_calculation(&map);
}