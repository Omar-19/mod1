/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_h.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:43:26 by btheia            #+#    #+#             */
/*   Updated: 2020/07/05 17:23:48 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_H_H
# define MOD_H_H
# define MAP_SIZE 90000
# define ROW_SIZE 300
# define SIZE_M 20000
# define RADIUS 150
# define POWER 6
# define EDGE 1
# define GL_SILENCE_DEPRECATION
# include "../ft_printf/includes/header.h"
# include <math.h>
# include <stdio.h>
# include <SDL.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>

typedef struct			s_point
{
	float				z;
	double				d_io;
	int					op;
	int					x;
	int					y;
	int					x1;
	int					y1;
	float				wh;
	float				wh1;
	int					h;
}						t_point;

typedef struct			s_listp
{
	int					x;
	int					y;
	float				z;
	int					op;
	struct s_listp		*next;
}						t_listp;

typedef struct			s_map
{
	int					pol;
	int					ar;
	int					size_a;
	int					start;
	int					rain_s;
	int					max_h;
	int					flow;
	int					rd;
	int					rain_time;
	double				povyx;
	double				povyx_d;
	double				povz;
	double				povz_d;
	int					running;
	int					water;
	int					fd;
	t_point				*mp;
	t_listp				*points;
}						t_map;

int						gnl(const int fd, char **line);
void					init_map(t_point *mp);
void					init_coor(t_point	*mp, char **tab, t_map *map);
void					read_map(int fd, t_map *map);
void					init_x_y(t_map *map);
void					altitude_calculation(t_map *map);
void					null_border(t_map *map);
void					up_water(t_point *mp, int key);
float					check_w(t_point *mp, int *a, float n, int *num);
void					wave_calc(t_point *mp, t_map *map, int i);
void					update_water(t_point *mp);
void					add_wave(t_map *map);
void					add_rain(t_map *map);
float					iso_x(float x, float y, float z, int i);
void					water_f(int key, t_map *map);
void					psudo(t_point *mp, int x, int y);
void					add_point(t_listp **head, int x, int y, int type);
void					water_pol2(int i, int j, t_map *map);
void					save_file(t_map *map);
void					rain_info(t_map *map, int key);
void					water_pol(int i, int j, t_map *map);
void					water_pol_h(int i, int j, t_map *map);
int						h_bool(int i, int j, t_map *map);
void					keyb2(SDL_Event event, t_map *map);
void					delete_mem(t_map *map, int key);
void					getnewcol(double max, double z, double *rgb);
void					getnewcol2(double proc, double *rgb);
void					getnewcol3(double proc, double *rgb);
void					endsdl(void);
void					earn_c(int i, int j, t_map *map, double *rgb);
int						len_tab(char **tab);

#endif
