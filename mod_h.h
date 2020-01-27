#ifndef MOD_H
# define MOD_H
# define MAP_SIZE 10000
# define ROW_SIZE 100
# define RADIUS 30
# define POWER 2
# define EDGE 1
# include "libft/includes/header.h"
# include <math.h>

typedef struct			s_point
{
	int					z;
	// double		 		lambda;
	double				d_io;
	int					op;
	int					x;
	int					y;
}						t_point;

typedef struct			s_map
{
	int					pol;
	t_point				mp[MAP_SIZE];
}						t_map;

int						gnl(const int fd, char **line);
void					init_map(t_point *mp);
void					init_coor(t_point	*mp, char **tab);
void    				read_map(int fd, t_map *map);
void					init_x_y(t_map *map);
void					altitude_calculation(t_map *map);
void					null_border(t_map *map);

#endif