#ifndef MOD_H
# define MOD_H
# include "stdio.h"
# include "stdlib.h"
# define MAP_SIZE 9
# define RADIUS 2
# define POWER 2

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

#endif