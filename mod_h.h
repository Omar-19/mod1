/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_h.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:43:26 by btheia            #+#    #+#             */
/*   Updated: 2020/03/20 02:59:26 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_H
# define MOD_H
# define MAP_SIZE 90000
# define ROW_SIZE 300
# define SIZE_M 20000
# define RADIUS 90
# define POWER 2
# define EDGE 1
# define GL_SILENCE_DEPRECATION
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
	int					x1;
	int					y1;
	float				wh;
	float				wh1;
}						t_point;

typedef struct			s_map
{
	int					pol;
	int					ar;
	int					size_a;
	int					start;
	int					rain_s;
	int					max_h;
	t_point				*mp;
}						t_map;

int						gnl(const int fd, char **line);
void					init_map(t_point *mp);
void					init_coor(t_point	*mp, char **tab, t_map *map);
void    				read_map(int fd, t_map *map);
void					init_x_y(t_map *map);
void					altitude_calculation(t_map *map);
void					null_border(t_map *map);
void    				up_water(t_point *mp);
float					check_w(t_point *mp, int i, int j, float n, int *num);
void					wave_calc(t_point *mp);
void					update_water(t_point *mp);
void					add_wave(t_map *map);
void					add_rain(t_map *map);
float					iso_x(float x, float y, float z, int i);

#endif
