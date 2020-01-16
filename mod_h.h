#ifndef MOD_H
# define MOD_H
# include "libft/includes/header.h"
# define MAP_SIZE 10000

typedef struct			s_point
{
	int					z;
	int					op;
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


#endif