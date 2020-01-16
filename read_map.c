#include "mod_h.h"

void	init_map(t_point *mp)
{
	int	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		mp[i].z = 0;
		mp[i].op = 0;
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
		ft_printf("%s %s %s\n", fl[0], fl[1], fl[2]);
		ft_printf("%d %d %d\n", (ft_atoi(fl[0]) / 2), (ft_atoi(fl[1])/ 200),ft_atoi(fl[2]) / 200);
		mp[(ft_atoi(fl[0]) / 2) + (ft_atoi(fl[1])/ 200)].z = ft_atoi(fl[2]) / 200;
		mp[(ft_atoi(fl[0]) / 2) + (ft_atoi(fl[1])/ 200)].op = 1;
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